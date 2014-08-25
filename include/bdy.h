#ifndef BDY_Y
#define BDY_Y

typedef struct bdy {
    uint32_t    kind;           // 0x0
    int32_t     x;              // 0x4
    int32_t     y;              // 0x8
    int32_t     w;              // 0xC
    int32_t     h;              // 0x10
    uint32_t    _unknown1;      // 0x14
    uint32_t    _unknown2;      // 0x18
    uint32_t    _unknown3;      // 0x1C
    uint32_t    _unknown4;      // 0x20
    uint32_t    _unknown5;      // 0x24
} bdy_t;

#endif
