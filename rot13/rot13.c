#include <stddef.h>

// TODO: move to some wasm.h
#define WASM_EXPORT __attribute__((used)) __attribute__((visibility("default")))

// TODO: move to libc/string/strlen.c
size_t strlen(const char *in) {
  size_t i = 0;
  while (in[i])
    i++;
  return i;
}

WASM_EXPORT char *rot13(char *in) {
  size_t len = strlen(in);
  size_t i;
  for (i = 0; i < len; i++) {
    if ((in[i] >= 'a' && in[i] <= 'm') || (in[i] >= 'A' && in[i] <= 'M')) {
      in[i] += 13;
    } else if ((in[i] >= 'n' && in[i] <= 'z') ||
               (in[i] >= 'N' && in[i] <= 'Z')) {
      in[i] -= 13;
    }
  }
  return in;
}
