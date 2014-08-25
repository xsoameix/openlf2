#ifndef FILE_H
#define FILE_H

#include <stdint.h>
#include "itr.h"
#include "frame.h"

typedef struct file {
    // firen_ball_dat:    0xF
    // woody_ball_dat:    0xF
    // henry_wind_dat:    0xF
    // henry_arrow2_dat:  0xF
    // john_ball_dat:     0xF
    // john_biscuit_dat:  0xF
    // deep_ball_dat:     0xF
    // freeze_ball_dat:   0xF
    // dennis_ball_dat:   0xF
    // dennis_chase_dat:  0xF
    // davis_ball_dat:    0xF
    // julian_ball2_dat:  0xF
    // firzen_ball_dat:   0xF
    // bat_ball_dat:      0xF
    // justin_ball_dat:   0xF
    // jan_chase_dat:     0xF
    // jack_ball_dat:     0xF
    // firen_flame_dat:   0x4C
    // freeze_column_dat: 0x4D
    // bat_chase_dat:     0x52
    // julian_ball_dat:   0x54
    // knife_dat:         0x2E(46)
    // <_dat              0x2E(46)
    // hoe_dat:           0x3E(62)
    // baseball_dat:      0x40(64)
    // beer_dat:          0x41(65)
    // milk_dat:          0x41(65)
    // stone_dat:         0x43(67)
    uint32_t _padding1[41];
    uint32_t _unknown1;            // 0xA4
    uint32_t _padding2;
    uint32_t _unknown2;            // 0xAC
    uint32_t _padding3[5];
    itr_t    attaking_itrs[4];     // 0xC4
    uint32_t _padding4[316];
    uint32_t id;                   // 0x6F4
    uint32_t type;                 // 0x6F8
    uint32_t _padding5[42];
    frame_t  frames[400];          // 0x7A4
} file_t;

#endif
