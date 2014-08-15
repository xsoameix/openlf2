#include <string.h>
#include "util.h"

void
write_memory(void * addr, void * data, uint32_t data_len) {
    DWORD old_protect;
    VirtualProtect(addr, data_len, PAGE_EXECUTE_READWRITE, &old_protect);
    memmove(addr, data, data_len);
    VirtualProtect(addr, data_len, old_protect, &old_protect);
}

void
jmp_patch(void * from, void * to) {
    char jmp[5] = "\xE9\0\0\0\0";
    * (uint32_t *) &jmp[1] = to - (from + 5);
    write_memory(from, &jmp, 5);
}

void
call_patch(void * from, void * to) {
    char call[5] = "\xE8\0\0\0\0";
    * (uint32_t *) &call[1] = to - (from + 5);
    write_memory(from, &call, 5);
}
