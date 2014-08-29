#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include "util.h"
#include "lf2.h"
#include "class_global.h"
#include "static.h"

// WARNING: Test for fun !!!
void
shaking(void) {
    uint32_t attacker_id;
    uint32_t injured_id;
    itr_t * itr;
    asm("movl %%ebx, %%eax" : "=r" (attacker_id));
    asm("movl %%edi, %%eax" : "=r" (injured_id));
    asm("movl 16(%%ebp), %%eax" : "=r" (itr));
    object_t * attacker = global->objects[attacker_id];
    object_t * injured = global->objects[injured_id];
    object_t * me = global->objects[2];
    if (attacker_id == 2 && injured->file->type == character_type) {
        uint32_t holder_id = attacker_id;
        object_t * holder = attacker;
        //if (holder->weapon_id > 0 && holder->weapon_type > 0) {
        //    holder_id = holder->weapon_id;
        //    holder = global->objects[holder_id];
        //}
        //holder->weapon_type = lignt_weapon_type;
        holder->weapon_id = injured_id;
        injured->owner = holder_id;
        injured->pic_x_gain = 0;
        //attacker->holder_id = holder_id;
        //attacker->weapon_type = - lignt_weapon_type;
        //attacker->frame_id1 = 0;
        //uint32_t weapon_id = attacker->weapon_id;
        //uint8_t is_exists = global->is_object_exists[weapon_id];
        //if (weapon_id != 0 && is_exists) {
        //    object_t * weapon = global->objects[weapon_id];
        //    printf("weapon_id %" PRIu32 ", weapon team %" PRIu32 "\n",
        //            weapon_id, weapon->team);
        //    weapon->team = holder->team;
        //    printf("weapon_id %" PRIu32 ", weapon team %" PRIu32 "\n",
        //            weapon_id, weapon->team);
        //}
        //fflush(stdout);
    }
    uint32_t weapon_id = injured->weapon_id;
    object_t * weapon = global->objects[weapon_id];
    if (injured_id == 2 && weapon_id > 0) {
        uint32_t injury = itr->injury;
        injured->hp += injury;
        injured->dark_hp += injury / 6;
        injured->hp_lost -= injury;
        weapon->hp -= injury;
        weapon->dark_hp -= injury / 6;
        weapon->hp_lost += injury;
        weapon->fall += itr->fall;
        weapon->y_velocity += itr->dvy;
        weapon->x_velocity += injured->pic_x_gain;
        weapon->frame_id1 = injured->frame_id1;
        weapon->shaking -= 3;
        injured->fall = 0;
        itr->fall = 0;
        if (itr->effect % 10 == 2) {
            itr->effect = 1;
        }
        injured->frame_id1 = injured->frame_id4;
        injured->y_velocity = 0;
        injured->y_accl = 0;
        injured->pic_x_gain = 0;
    }
        //asm("leave");
        //asm("movl $0x00431ABB, %eax");
        //asm("jmp *%eax");
    asm("movl %%eax, %%ebx" : : "r" (attacker_id));
    asm("movl %%eax, %%edi" : : "r" (injured_id));
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
    object_t * attacker = global->objects[attacker_id];
    object_t * injured = global->objects[injured_id];
    object_t * me = global->objects[2];
    if (injured->team == me->team) {
        itr_t * itr;
        asm("movl 16(%%ebp), %%eax" : "=r" (itr));
        injured->fall = 0;
        injured->hp += itr->injury;
        injured->mp = 500;
        injured->dark_hp += injured->hp;
        injured->hp_lost -= itr->injury;
    }
    asm("movl %%eax, %%eax" : : "r" (injured));
    asm("leave");
    asm("movl $0x0042EB1A, %ecx");
    asm("jmp *%ecx");
}

void
success(void) {
    uint32_t attacker_id;
    uint32_t injured_id;
    itr_t * itr;
    asm("movl %%ebx, %%eax" : "=r" (attacker_id));
    asm("movl %%edi, %%eax" : "=r" (injured_id));
    asm("movl %%edx, %%eax" : "=r" (itr));
    object_t * attacker = global->objects[attacker_id];
    object_t * injured = global->objects[injured_id];
    object_t * me = global->objects[2];
    if (attacker->team == me->team) {
        asm("leave");
        asm("movl $0x0042E87D, %eax");
        asm("jmp *%eax");
    }
    uint32_t bdefend = itr->bdefend;
    asm("movl %%eax, %%ecx" : : "r" (bdefend));
    asm("cmp $0x64, %ecx");
    asm("movl %ecx,20(%ebp)");
    asm("leave");
    asm("movl $0x0042E626, %eax");
    asm("jmp *%eax");
}

void
hello(void) {
  puts("Openlf2.dll loading ...");
  fflush(stdout);
  jmp_patch((void *) 0x00403270, func_403270_teleport);
  jmp_patch((void *) 0x00417170, func_417170_random);
  jmp_patch((void *) 0x00417400, func_417400_does_attack_success);
  puts("Openlf2.dll patched !");
  fflush(stdout);
}
