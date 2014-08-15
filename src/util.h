#ifndef UTIL_H
#define UTIL_H

#include <windows.h>
#include <stdint.h>

void write_memory(void * addr, void * data, uint32_t data_len);
void jmp_patch(void * from, void * to);

#endif
