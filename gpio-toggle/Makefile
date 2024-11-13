EXE := gpiod
OBJS := gpiod.o
INSTALL_DIR ?= ./.install

CFLAGS += $(shell pkg-config --cflags libgpiod)
LDLIBS += $(shell pkg-config --libs libgpiod)

all: $(EXE)

$(EXE): $(OBJS)

install: $(EXE)
	install -D $(INSTALL_DIR)
	install $(EXE) $(INSTALL_DIR)

clean:
	-$(RM) $(OBJS) $(EXE)
