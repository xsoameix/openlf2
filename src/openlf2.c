#include <stdio.h>
#include "util.h"
#include "lf2.h"
#include "class_global.h"

void
hello(void) {
    puts("Openlf2.dll loading ...");
    fflush(stdout);
    jmp_patch((void *) 0x00403270, func_403270_teleport);
    puts("Openlf2.dll patched !");
    fflush(stdout);
}
