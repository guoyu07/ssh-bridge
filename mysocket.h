#ifndef _MYSOCKET_H_
#define _MYSOCKET_H_

#include <stdint.h>
#include <errno.h>
#include <sys/types.h>

int myread(int, uint8_t *, size_t);
int mywrite(int, uint8_t *, size_t);

#endif
