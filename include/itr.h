#ifndef ITR_H
#define ITR_H

typedef struct itr {
    uint32_t    kind;           // 0x0
    int32_t     x;              // 0x4
    int32_t     y;              // 0x8
    uint32_t    w;              // 0xC
    uint32_t    h;              // 0x10
    int32_t     dvx;            // 0x14
    int32_t     dvy;            // 0x18
    uint32_t    fall;           // 0x1C
    uint32_t    arest;          // 0x20
    uint32_t    vrest;          // 0x24
    uint32_t    respond;        // 0x28
    uint32_t    effect;         // 0x2C
    uint32_t    catching_act_1; // 0x30
    uint32_t    catching_act_2; // 0x34
    uint32_t    caught_act_1;   // 0x38
    uint32_t    caught_act_2;   // 0x3C
    uint32_t    bdefend;        // 0x40
    int32_t     injury;         // 0x44
    uint32_t    zwidth;         // 0x48
    uint32_t    _unknown1;      // 0x4C
} itr_t;

#endif
