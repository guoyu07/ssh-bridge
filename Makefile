BIN := xor
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS := -O2 -DMYLOG

all: $(BIN)

-include $(SRCS:.c=.d)

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(BIN): $(OBJS)
	gcc -o $@ $(CFLAGS) $^ $(LDFLAGS)
	strip $@

clean:
	-rm -f *.d
	-rm -f *.d.*
	-rm -f *.o
	-rm -f $(BIN)

.PHONY: all clean
