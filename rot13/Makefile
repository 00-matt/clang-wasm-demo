MAKEFLAGS += -r

CC := clang-8
CFLAGS := -Wall \
			-Wextra \
			--target=wasm32 \
			-Os \
			-nostdlib \
			-fvisibility=hidden
LD := wasm-ld
LDFLAGS := --no-entry --export-dynamic --strip-all --import-memory
RM := rm -f

OBJECTS := rot13.o

.PHONY: all clean

all: library.wasm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

library.wasm: $(OBJECTS)
	$(LD) $(LDFLAGS) $< -o $@

clean:
	$(RM) library.wasm $(OBJECTS)
