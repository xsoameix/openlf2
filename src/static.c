#include "static.h"

uint32_t
func_417170_random(uint32_t unused, uint32_t range) {
  if (range <= 0) {
    return 0;
  }
  uint32_t * _450C34 = (void *) 0x00450C34;
  uint32_t * _450BCC = (void *) 0x00450BCC;
  uint32_t next_i = (* _450C34 + 1) % 1234;
  uint32_t next_j = (* _450BCC + 1) % 3000;
  * _450C34 = next_i;
  * _450BCC = next_j;
  uint8_t * _44FF90 = (void *) 0x0044FF90;
  return (next_i + _44FF90[next_j]) % range;
}
