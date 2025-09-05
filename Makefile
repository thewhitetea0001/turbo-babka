CC = gcc
CFLAGS = -I/nix/store/i4n76zsbk93zpgfvrpazn4954xphqw24-concord-2.3.0/include -Imodules/events/headers -Imodules/commands/headers -Wall -Wextra -O2
LDFLAGS = -L/nix/store/i4n76zsbk93zpgfvrpazn4954xphqw24-concord-2.3.0/lib
LIBS = -ldiscord -lcurl -lpthread -lm -lz

SRCS = main.c modules/events/source/on_ready.c \
			 				modules/events/source/on_member_add.c \
							modules/commands/source/status.c
OBJS = $(SRCS:.c=.o)
BIN = main

.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BIN)
