#include <stdio.h>
#include "util.h"
#include "lf2.h"
#include "class_global.h"
#include "static.h"

void
hello(void) {
    puts("Openlf2.dll loading ...");
    fflush(stdout);
    jmp_patch((void *) 0x00403270, func_403270_teleport);
    jmp_patch((void *) 0x00417170, func_417170_random);
    puts("Openlf2.dll patched !");
    fflush(stdout);
}
