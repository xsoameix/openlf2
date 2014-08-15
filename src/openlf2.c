#include <stdio.h>
#include "util.h"

void
attacker_shaking(void) {
    asm("pop %ebp");
    asm("movl $0x0042F2C1, %eax");
    asm("jmp *%eax");
}

void
hello(void) {
    puts("Openlf2.dll loading ...");
    fflush(stdout);
    jmp_patch((void *) 0x0042F2AE, attacker_shaking);
    puts("Openlf2.dll patched !");
    fflush(stdout);
}
