#include <stdio.h>
#include "util.h"
#include "lf2.h"

// WARNING: Test for fun !!!
void
shaking(void) {
    uint32_t attacker_id;
    uint32_t injured_id;
    asm("movl %%ebx, %%eax" : "=r" (attacker_id));
    asm("movl %%edi, %%eax" : "=r" (injured_id));
    object * attacker = global->objects[attacker_id];
    object * me = global->objects[2];
    if (attacker->shaking >= 0) {
        if (attacker->team == me->team) {
        } else {
            attacker->facing = 1 - attacker->facing;
            if (attacker->file->type != character_type) {
                attacker->team = me->team;
            }
            if (attacker->frame_id1 == hitting_frame) {
                attacker->frame_id1 = in_the_sky_frame;
            }
            attacker->x_velocity = - attacker->x_velocity;
            attacker->y_velocity = - attacker->y_velocity;
        }
    }
    object * injured = global->objects[injured_id];
    if (injured->team == me->team) {
        injured->pic_x_gain = 0;
        asm("leave");
        asm("movl $0x00431ABB, %eax");
        asm("jmp *%eax");
    } else {
        injured->shaking = -100;
    }
    asm("leave");
    asm("movl 12(%esp), %ecx");
    asm("movl $0x0042F2D6, %eax");
    asm("jmp *%eax");
}

// WARNING: Test for fun !!!
void
frame_id(void) {
    uint32_t attacker_id;
    uint32_t injured_id;
    asm("movl %%ebx, %%eax" : "=r" (attacker_id));
    asm("movl %%edi, %%eax" : "=r" (injured_id));
    object * attacker = global->objects[attacker_id];
    object * injured = global->objects[injured_id];
    object * me = global->objects[2];
    if (injured->team == me->team) {
        itr * itr;
        asm("movl 16(%%ebp), %%eax" : "=r" (itr));
        injured->fall = 0;
        injured->hp += itr->injury;
        injured->dark_hp += itr->injury / 6;
        injured->hp_lost -= itr->injury;
    }
    asm("movl %%eax, %%eax" : : "r" (injured));
    asm("leave");
    asm("movl $0x0042EB1A, %ecx");
    asm("jmp *%ecx");
}

void
hello(void) {
    puts("Openlf2.dll loading ...");
    fflush(stdout);
    jmp_patch((void *) 0x0042F2AE, shaking);
    jmp_patch((void *) 0x0042EB13, frame_id);
    puts("Openlf2.dll patched !");
    fflush(stdout);
}
