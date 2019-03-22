MAKEFLAGS += -r

WARNINGS := -Wall -Wextra

CC := clang-8
CFLAGS := $(WARNINGS) \
			--target=wasm32 \
			-Os \
			-nostdlib
LD := wasm-ld
LDFLAGS := --no-entry --export-all
RM := rm -f

.PHONY: all clean

all: library.wasm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

library.wasm: fact.o
	$(LD) $(LDFLAGS) $< -o $@

clean:
	$(RM) *.o *.wasm
