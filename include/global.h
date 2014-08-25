#ifndef GLOBAL_H
#define GLOBAL_H

#include "object.h"
#include "file.h"

typedef struct global {
    uint32_t game_state;
    uint8_t  is_object_exists[400];

    // objects
    // format: [name][size]
    //   players[4]
    //   ?[6]
    //   computers[8]
    //   ?[2]
    //   characters_or_drinks[30]
    //   weapons_or_attacks_or_criminals[350]
    object_t * objects[400];

    // file[ 0]: data\template.dat
    // file[ 1]: data\julian.dat
    // file[ 2]: data\firzen.dat
    // file[ 3]: data\louisEX.dat
    // file[ 4]: data\bat.dat
    // file[ 5]: data\justin.dat
    // file[ 6]: data\knight.dat
    // file[ 7]: data\jan.dat
    // file[ 8]: data\monk.dat
    // file[ 9]: data\sorcerer.dat
    // file[10]: data\jack.dat
    // file[11]: data\mark.dat
    // file[12]: data\hunter.dat
    // file[13]: data\bandit.dat
    // file[14]: data\deep.dat
    // file[15]: data\john.dat
    // file[16]: data\henry.dat
    // file[17]: data\rudolf.dat
    // file[18]: data\louis.dat
    // file[19]: data\firen.dat
    // file[20]: data\freeze.dat
    // file[21]: data\dennis.dat
    // file[22]: data\woody.dat
    // file[23]: data\davis.dat
    // file[24]: data\weapon0.dat   //stick
    // file[25]: data\weapon2.dat   //hoe
    // file[26]: data\weapon4.dat   //knife
    // file[27]: data\weapon5.dat   //baseball
    // file[28]: data\weapon6.dat   //milk
    // file[29]: data\weapon1.dat   //stone
    // file[30]: data\weapon3.dat   //wooden_box
    // file[31]: data\weapon8.dat   //beer
    // file[32]: data\weapon9.dat   //<
    // file[33]: data\weapon10.dat  //louis_armour
    // file[34]: data\weapon11.dat  //louis_armour
    // file[35]: data\criminal.dat  //criminal
    // file[36]: data\john_ball.dat
    // file[37]: data\henry_arrow1.dat
    // file[38]: data\rudolf_weapon.dat
    // file[39]: data\deep_ball.dat
    // file[40]: data\henry_wind.dat
    // file[41]: data\dennis_ball.dat
    // file[42]: data\woody_ball.dat
    // file[43]: data\davis_ball.dat
    // file[44]: data\henry_arrow2.dat
    // file[45]: data\freeze_ball.dat
    // file[46]: data\firen_ball.dat
    // file[47]: data\firen_flame.dat
    // file[48]: data\freeze_column.dat
    // file[49]: data\weapon7.dat   //ice_sword
    // file[50]: data\john_biscuit.dat
    // file[51]: data\dennis_chase.dat
    // file[52]: data\jack_ball.dat
    // file[53]: data\jan_chaseh.dat
    // file[54]: data\jan_chase.dat
    // file[55]: data\firzen_chasef.dat
    // file[56]: data\firzen_chasei.dat
    // file[57]: data\firzen_ball.dat
    // file[58]: data\bat_ball.dat
    // file[59]: data\bat_chase.dat
    // file[60]: data\justin_ball.dat
    // file[61]: data\julian_ball.dat
    // file[62]: data\julian_ball2.dat
    // file[63]: data\etc.dat
    // file[64]: data\broken_weapon.dat
    file_t * (* files)[65];
} global_t;

#endif
