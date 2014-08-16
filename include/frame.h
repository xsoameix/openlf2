#ifndef FRAME_H
#define FRAME_H

struct cpoint_catching {
    uint32_t    injury;             // 0x94
};

struct cpoint_caught {
    uint32_t    front_hurt_act;     // 0x94
    uint32_t    back_hurt_act;      // 0x98
};

typedef struct _frame {
    uint32_t    state;                // 0x8
    double      dvy;                  // 0x18
    uint32_t    cpoint_kind;          // 0x88
    union {
        struct cpoint_catching cpoint_catching; // cpoint_kind == catching_kind
        struct cpoint_caught   cpoint_caught;   // cpoint_kind == caught_kind
    };
    uint32_t    hurtable;             // 0xB4
    uint32_t    attaking;             // 0xE8
    uint32_t    itrs_size;            // 0x128
    uint32_t    bdys_size;            // 0x12C
    uint32_t    * itrs;               // 0x130
    uint32_t    * bdys;               // 0x134
} frame;

#endif
