#ifndef FRAME_H
#define FRAME_H

#include "itr.h"
#include "bdy.h"

typedef struct opoint {
    uint32_t    kind;                 // 0x58
    int32_t     x;                    // 0x5C
    int32_t     y;                    // 0x60
    uint32_t    action;               // 0x60
    int32_t     dvx;                  // 0x64
    int32_t     dvy;                  // 0x68
    uint32_t    oid;                  // 0x6C
    int32_t     facing;               // 0x70
} opoint_t;

typedef struct bpoint {
    int32_t     x;                    // 0x7C
    int32_t     y;                    // 0x80
} bpoint_t;

typedef struct cpoint {
    uint32_t    kind;                 // 0x88
    int32_t     x;                    // 0x8C
    int32_t     y;                    // 0x90
    union {
        // when kind == catching_kind
        struct {
            uint32_t    injury;         // 0x94
            uint32_t    cover;          // 0x98
            uint32_t    vaction;        // 0x9C
            uint32_t    aaction;        // 0xA0
            uint32_t    jaction;        // 0xA4
            uint32_t    daction;        // 0xA8
            int32_t     throwx;         // 0xAC
            int32_t     throwy;         // 0xB0
            uint32_t    hurtable;       // 0xB4
            int32_t     decrease;       // 0xB8
            int32_t     dicontrol;      // 0xBC
            uint32_t    taction;        // 0xC0
            int32_t     throwinjury;    // 0xC4
            int32_t     throwz;         // 0xC8
        };
        // when kind == caught_kind
        struct {
            uint32_t    front_hurt_act; // 0x94
            uint32_t    back_hurt_act;  // 0x98
        };
    };
} cpoint_t;

typedef struct wpoint {
    uint32_t    kind;                 // 0xD8
    int32_t     x;                    // 0xDC
    int32_t     y;                    // 0xE0
    uint32_t    weaponact;            // 0xE4
    uint32_t    attacking;            // 0xE8
    uint32_t    cover;                // 0xEC
    int32_t     dvx;                  // 0xF0
    int32_t     dvy;                  // 0xF4
    int32_t     dvz;                  // 0xF8
} wpoint_t;

typedef struct frame {
    uint32_t    present;              // 0x0
    uint32_t    pic;                  // 0x4
    uint32_t    state;                // 0x8
    uint32_t    wait;                 // 0xC
    int32_t     next;                 // 0x10
    int32_t     dvx;                  // 0x14
    int32_t     dvy;                  // 0x18
    int32_t     dvz;                  // 0x1C
    uint32_t    _unknown1;            // 0x20
    uint32_t    hit_a;                // 0x24
    uint32_t    hit_d;                // 0x28
    uint32_t    hit_j;                // 0x2C
    uint32_t    hit_Fa;               // 0x30
    uint32_t    hit_Ua;               // 0x34
    uint32_t    hit_Da;               // 0x38
    uint32_t    hit_Fj;               // 0x3C
    uint32_t    hit_Uj;               // 0x40
    uint32_t    hit_Dj;               // 0x44
    uint32_t    hit_ja;               // 0x48
    int32_t     mp;                   // 0x4C
    int32_t     centerx;              // 0x50
    int32_t     centery;              // 0x54
    opoint_t    opoint;             // 0x58
    uint32_t    _unknown2;            // 0x74
    uint32_t    _unknown3;            // 0x78
    bpoint_t    bpoint;             // 0x7C
    cpoint_t    cpoint;             // 0x88
    uint32_t    _unknown4;            // 0xCC
    uint32_t    _unknown5;            // 0xD0
    uint32_t    _unknown6;            // 0xD4
    wpoint_t     wpoint;             // 0x88
    uint32_t    _unknown7;            // 0xFC
    uint32_t    _unknown8;            // 0x100
    uint32_t    _unknown9;            // 0x104
    uint32_t    _unknown10;           // 0x108
    uint32_t    _unknown11;           // 0x10C
    uint32_t    _unknown12;           // 0x110
    uint32_t    _unknown13;           // 0x114
    uint32_t    _unknown14;           // 0x118
    uint32_t    _unknown15;           // 0x11C
    uint32_t    _unknown16;           // 0x120
    uint32_t    _unknown17;           // 0x124
    uint32_t    itrs_size;            // 0x128
    uint32_t    bdys_size;            // 0x12C
    itr_t       * itrs;               // 0x130
    bdy_t       * bdys;               // 0x134
    uint32_t    _unknown18;           // 0x138
    uint32_t    _unknown19;           // 0x13C
    uint32_t    _unknown20;           // 0x140
    uint32_t    _unknown21;           // 0x144
    uint32_t    _unknown22;           // 0x148
    uint32_t    _unknown23;           // 0x14C
    uint32_t    _unknown24;           // 0x150
    uint32_t    _unknown25;           // 0x154
    uint32_t    _unknown26;           // 0x158
    char        name[4];              // 0x15C
    uint32_t    continue1;            // 0x160
    uint32_t    continue2;            // 0x164
    uint32_t    continue3;            // 0x168
    uint32_t    continue4;            // 0x16C
    uint32_t    sound;                // 0x170
    uint32_t    _unknown27;           // 0x174
} frame_t;

#endif
