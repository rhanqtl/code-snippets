#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void _panic(const char *filename, const int line_number, const int error_number,
            const char *msg);

#define panic(msg)                                                             \
  do {                                                                         \
    _panic(__FILE__, __LINE__, errno, msg);                                    \
  } while (0)

// panicf is not thread-safe
#define panicf(fmt, ...)                                                       \
  do {                                                                         \
    char strbuf[1024];                                                         \
    int nw = snprintf(strbuf, sizeof(strbuf), fmt, __VA_ARGS__);               \
    strbuf[nw] = '\0';                                                         \
    panic(strbuf);                                                             \
  } while (0)

void _panic(const char *filename, const int line_number, const int error_number,
            const char *msg) {
  fprintf(stderr, "%s:%d - errno: %d, msg: %s\n", filename, line_number,
          error_number, msg);
  exit(error_number);
}

#endif