#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#define GPIO_CHIP "/dev/gpiochip0"
#define GPIO_LINE 17

int main (int argc, char* argv[]){

	struct gpiod_chip* chip;
	struct gpiod_line* line;
	int value = 0;

	chip = gpiod_chip_open(GPIO_CHIP);
	if (!chip) {
		perror("gpiod_chip_open, error");
		return 1;
	}

	line = gpiod_chip_get_line(chip, GPIO_LINE);
	if (!line){
		perror("gpiod_line_chip_open, error");
		gpiod_chip_close(chip);
		return 1;
	}

	if (gpiod_line_request_output(line,"gpio-toggle",0) < 0){
		perror("Ta mère!");
		gpiod_chip_close(chip);
		return 1;
	}

	while (1){
		value = !value;
		gpiod_line_set_value(line,value);
		printf("GPIO%d set to %d\n", GPIO_LINE, value);
		sleep(1);
	}
	gpiod_line_release(line);
	gpiod_chip_close(chip);

	return 0;

}
