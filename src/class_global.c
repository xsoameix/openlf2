#include <math.h>
#include "class_global.h"

void
func_403270_teleport(uint32_t teleported_id, uint32_t teleport_to) {
    global_t * global;
    asm("movl %%ecx, %%eax" : "=r" (global));
    asm("push %ebx");
    asm("push %ebp");
    asm("push %esi");
    asm("push %edi");
    asm("addl $16, %esp");
    if (teleport_to == teleport_to_enemy) {
        uint32_t closest_object_id = -1;
        uint32_t min_distance = 10000;
        object_t ** object_ptr = global->objects;
        for (uint32_t object_id = 0;
                object_id < max_objects_size;
                object_id++, object_ptr++) {
            uint8_t object_exists = global->is_object_exists[object_id];
            object_t * object = * object_ptr;
            object_t * teleported = global->objects[teleported_id];
            uint32_t distance =
                abs(object->z - teleported->z) +
                abs(object->x - teleported->x);
            if (object_id != teleported_id &&
                    object_exists &&
                    object->file->type == character_type &&
                    object->team != teleported->team &&
                    object->hp > 0 &&
                    distance < min_distance) {
                closest_object_id = object_id;
                min_distance = distance;
            }
        }
        if (closest_object_id == -1) {
            object_t * teleported = global->objects[teleported_id];
            teleported->y = 0;
            teleported->y_position = teleported->y;
        } else {
            object_t * teleported = global->objects[teleported_id];
            object_t * closest_object = global->objects[closest_object_id];
            teleported->y = 0;
            teleported->z = closest_object->z + 1;
            int32_t closest_object_x = closest_object->x;
            if (teleported->facing == facing_right) {
                closest_object_x -= 120;
            } else {
                closest_object_x += 120;
            }
            teleported->x = closest_object_x;
            teleported->x_position = teleported->x;
            teleported->y_position = teleported->y;
            teleported->z_position = teleported->z;
        }
    } else if (teleport_to == teleport_to_team) {
        uint32_t farthest_object_id = -1;
        int32_t max_distance = -1;
        object_t ** object_ptr = global->objects;
        for (uint32_t object_id = 0;
                object_id < max_objects_size;
                object_id++, object_ptr++) {
            uint8_t object_exists = global->is_object_exists[object_id];
            object_t * object = * object_ptr;
            object_t * teleported = global->objects[teleported_id];
            int32_t distance =
                abs(object->z - teleported->z) +
                abs(object->x - teleported->x);
            if (object_id != teleported_id &&
                    object_exists &&
                    object->file->type == character_type &&
                    object->team == teleported->team &&
                    object->hp > 0 &&
                    distance > max_distance) {
                farthest_object_id = object_id;
                max_distance = distance;
            }
        }
        if (farthest_object_id == -1) {
            object_t * teleported = global->objects[teleported_id];
            teleported->y = 0;
            teleported->y_position = teleported->y;
        } else {
            object_t * teleported = global->objects[teleported_id];
            object_t * farthest_object = global->objects[farthest_object_id];
            teleported->y = 0;
            teleported->z = farthest_object->z + 1;
            int32_t farthest_object_x = farthest_object->x;
            if (teleported->facing == facing_right) {
                farthest_object_x -= 60;
            } else {
                farthest_object_x += 60;
            }
            teleported->x = farthest_object_x;
            teleported->x_position = teleported->x;
            teleported->y_position = teleported->y;
            teleported->z_position = teleported->z;
        }
    } else {
        asm("subl $16, %esp");
        asm("pop %edi");
        asm("pop %esi");
        asm("pop %ebp");
        asm("pop %ebx");
        asm("leave");
        asm("ret $8");
        return;
    }
    object_t * teleported = global->objects[teleported_id];
    teleported->z_velocity = 0;
    teleported->x_velocity = 0;
    teleported->y_velocity = 0;
    asm("subl $16, %esp");
    asm("pop %edi");
    asm("pop %esi");
    asm("pop %ebp");
    asm("pop %ebx");
    asm("leave");
    asm("ret $8");
}
