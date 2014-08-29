#include <math.h>
#include <stdbool.h>
#include "static.h"
#include "class_global.h"

thiscall void
func_417400_does_attack_success(global_t * global, uint32_t attacker_id, uint32_t injured_id, uint32_t mode) {
  // attacker
  object_t * attacker = global->objects[attacker_id];
  uint32_t attacker_frame_id1 = attacker->frame_id1;
  uint32_t attacker_frame_id3 = attacker->frame_id3;
  uint32_t attacker_frame_id4 = attacker->frame_id4;
  file_t * attacker_file = attacker->file;
  frame_t * attacker_frame1 = &attacker_file->frames[attacker_frame_id1];
  frame_t * attacker_frame3 = &attacker_file->frames[attacker_frame_id3];
  frame_t * attacker_frame4 = &attacker_file->frames[attacker_frame_id4];
  // injured
  object_t * injured = global->objects[injured_id];
  uint32_t injured_frame_id1 = injured->frame_id1;
  uint32_t injured_frame_id3 = injured->frame_id3;
  uint32_t injured_frame_id4 = injured->frame_id4;
  file_t * injured_file = injured->file;
  frame_t * injured_frame1 = &injured_file->frames[injured_frame_id1];
  frame_t * injured_frame3 = &injured_file->frames[injured_frame_id3];
  frame_t * injured_frame4 = &injured_file->frames[injured_frame_id4];
  for (uint32_t itr_id = 0; itr_id < attacker_frame4->itrs_size; itr_id++) {
    itr_t * itr = &attacker_frame4->itrs[itr_id];
    for (uint32_t bdy_id = 0; bdy_id < injured_frame4->bdys_size; bdy_id++) {
      // freeze ball can't be attack by the other balls.
      if ((attacker_file->id == john_ball_dat ||
           attacker_file->id == deep_ball_dat ||
           attacker_file->id == dennis_ball_dat ||
           attacker_file->id == woody_ball_dat ||
           attacker_file->id == davis_ball_dat ||
           attacker_file->id == dennis_chase_dat ||
           attacker_file->id == jack_ball_dat
          ) &&
          injured_file->id == freeze_ball_dat &&
          // forcefield is in john_ball.dat, but it can attack freeze ball.
          itr->kind != itr_forcefield) {
        break;
      }
      // can only catch character
      if (itr->kind == itr_catch &&
          injured_file->type != character_type) {
        break;
      }
      if (itr->kind == itr_normal_attack) {
        if (itr->effect == shrafe_effect &&
            injured_file->type == character_type) {
          break;
        }
        if (itr->effect == fire_effect &&
            (injured_file->type != character_type ||
             injured_frame3->state == fire_state ||
             injured_frame3->state == burn_run_state)) {
          break;
        }
        if (itr->effect == burn_effect &&
            (injured_frame3->state == fire_state ||
             injured_frame3->state == burn_run_state)) {
          break;
        }
        // freeze column can't attack the one is freezed.
        if (itr->effect == column_effect &&
            injured_frame_id1 >= freeze_frame_start &&
            injured_frame_id1 <= freeze_frame_end) {
          break;
        }
        // burn run skill can't attack the one is burning.
        if (itr->effect == fire_effect &&
            attacker_frame3->state == burn_run_state &&
            injured_frame3->state == fire_state) {
          break;
        }
      }
      if (itr->kind == itr_heal &&
          injured_file->type != character_type) {
        break;
      }
      // only healball, stone, and box can attack the one is invincible
      if (injured->invincible_time != 0 &&
          itr->kind != itr_heal &&
          itr->kind != itr_stop) {
        break;
      }
      // thrown team can attack the one on same team.
      // character can pick again the light weapon picked before when rowing.
      // healball can attack the one on same team.
      // stone and box can stop character from moving.
      if (itr->kind < itr_thrown ||
          itr->kind == itr_super_punch ||
          (itr->kind == itr_forcefield && injured_file->type == character_type) ||
          itr->kind == itr_flute ||
          itr->kind == itr_float ||
          itr->kind == itr_fly ||
          itr->kind == itr_freeze) {
        // attacker can attack freezed character on same team.
        // attacker can attack picked caught character on same team.
        // attacker can attack freeze column on same team.
        // freeze column can't attack another one in same time.
        if (injured_frame1->state != ice_state &&
            injured_frame1->state != picked_caught_state &&
            (injured_file->id != freeze_column_dat ||
             (attacker_file->id == freeze_column_dat &&
              (injured_frame_id1 % 10 != 5 ||
               attacker_frame_id1 % 10 != 0)))) {
          // attacker can't attack the one on same team.
          if (attacker->team == injured->team &&
              attacker->team != no_team &&
              itr->kind != itr_heal &&
              // burning object can attack the one on same team except
              // flame and firen explosion.
              (attacker_frame1->state != fire_state ||
               itr->effect == flame_effect ||
               itr->effect == firen_explosion_effect
              ) &&
              // weapons and balls and drinks can attack the balls in
              // opposite directions.
              (attacker_file->type != character_type ||
               injured_file->type != attack_type ||
               attacker->facing == injured->facing
              ) &&
              // attacker can attack weapons and drinks on same team.
              injured_file->type != lignt_weapon_type &&
              injured_file->type != heavy_weapon_type &&
              injured_file->type != throw_weapon_type &&
              injured_file->type != drink_type) {
            break;
          }
        }
      }
      uint32_t holder_id = attacker->holder_id;
      object_t * holder = global->objects[holder_id];
      if (itr->kind == itr_strength_list &&
          // character can't use weapon to attack the one on same team.
          holder->team == injured->team &&
          holder->team != no_team &&
          // character can use weapon to attack freezed character on same team.
          injured_frame1->state != ice_state &&
          // character can use weapon to attack weapons and drinks on same team.
          injured_file->type != lignt_weapon_type &&
          injured_file->type != heavy_weapon_type &&
          injured_file->type != throw_weapon_type &&
          injured_file->type != drink_type &&
          // character can use weapon to attack freeze column on same team.
          // character can't use freeze column to attack another one in same time.
          (injured_file->id != freeze_column_dat ||
           (attacker_file->id == freeze_column_dat &&
            (injured->frame_id1 % 10 != 5 ||
             holder->frame_id1 % 10 != 0)))) {
        break;
      }
      bdy_t * bdy = &injured_frame4->bdys[bdy_id];
      int32_t bdy_left_boundary = (injured->facing == facing_right) ?
          injured->x - injured_frame4->centerx + bdy->x :
          injured->x + injured_frame4->centerx - bdy->w - bdy->x;
      int32_t bdy_top_boundary = injured->y - injured_frame4->centery + bdy->y;
      int32_t itr_left_boundary = (attacker->facing == facing_right) ?
          attacker->x - attacker_frame4->centerx + itr->x :
          attacker->x + attacker_frame4->centerx - itr->w - itr->x;
      int32_t itr_top_boundary = attacker->y - attacker_frame4->centery + itr->y;
      uint32_t itr_zwidth = itr->zwidth;
      if (itr_zwidth == 0) {
        itr_zwidth = 15;
      }
      bool in_z_boundary = abs(attacker->z - injured->z) < itr_zwidth;
      bool (* func_4171C0_is_itr_bdy_overlap)(
          int32_t, int32_t, uint32_t, uint32_t,
          int32_t, int32_t, uint32_t, uint32_t) = (void *) 0x004171C0;
      bool is_overlap = func_4171C0_is_itr_bdy_overlap(
          bdy_left_boundary, bdy_top_boundary, bdy->w, bdy->h,
          itr_left_boundary, itr_top_boundary, itr->w, itr->h);
      if (!is_overlap || !in_z_boundary) {
        continue;
      }
      uint8_t is_attack_success = bool_initial;
      if (injured_frame1->state == falling_state &&
          itr->fall <= 40 &&
          itr->kind != itr_flute &&
          itr->kind != itr_float) {
        is_attack_success = bool_false;
      }
      if (mode == stage_mode) {
        bool can_rescue_criminal = false;
        if ((attacker_file->type == character_type ||
             attacker_file->id == henry_arrow1_dat ||
             attacker_file->id == rudolf_weapon_dat) &&
            attacker->team != stage_enemy_team) {
          can_rescue_criminal = true;
        }
        uint8_t is_holder_exists = global->is_object_exists[holder_id];
        if (attacker->weapon_type < 0 &&
            is_holder_exists &&
            holder->file->type == character_type &&
            holder->team != stage_enemy_team) {
          can_rescue_criminal = true;
        }
        if (bdy->kind >= 1000 &&
            !can_rescue_criminal) {
          is_attack_success = bool_false;
        }
      }
      if (itr->vrest == 0 &&
          itr->kind != itr_catch_injured &&
          itr->kind != itr_pick_up_weapon &&
          itr->kind != itr_rowing_pick &&
          (injured_frame4->state != on_ground_state_1 ||
           (attacker_file->type > character_type &&
            attacker->weapon_type >= 0)
          ) &&
          is_attack_success == bool_initial) {
        uint32_t x_distance = abs(attacker->x - injured->x);
        if (attacker->weapon_type < 0) {
          if (attacker->holder_id == injured_id) {
            x_distance = 2000;
          } else {
            x_distance = abs(holder->x - injured->x);
          }
        }
        if (x_distance > attacker->attackable_distance ||
            (x_distance == attacker->attackable_distance &&
             func_417170_random(0, 2) != 0)) {
          continue;
        }
        attacker->attackable_distance = x_distance;
        attacker->injured_of_attack[0] = injured_id;
        attacker->itr_of_attack[0] = itr_id;
        attacker->successful_attacks = 1;
        continue;
      }
      if (attacker->successful_attacks >= 20 ||
          is_attack_success != bool_initial) {
        continue;
      }
      if (injured_frame4->state == on_ground_state_1 &&
          (attacker_file->type > character_type ||
           attacker->weapon_type < 0
          ) &&
          itr->kind != itr_pick_up_weapon &&
          itr->kind != itr_rowing_pick &&
          itr->kind != itr_flute) {
        is_attack_success = bool_false;
      }
      if (itr->kind == itr_catch_injured) {
        uint32_t x_distance = abs(attacker->x - injured->x);
        if (x_distance < injured->vulnerable_distance ||
            (x_distance == injured->vulnerable_distance &&
             func_417170_random(0, 2) == 0)) {
          injured->vulnerable_distance = x_distance;
        } else {
          is_attack_success = bool_false;
        }
      }
      if (itr->kind == itr_thrown &&
          attacker->thrown_injury != 0 &&
          is_attack_success != bool_false) {
        is_attack_success = bool_true;
      }
      if (itr->kind == itr_catch_injured &&
          ((attacker->click_right && attacker->x <  injured->x) ||
           (attacker->click_left  && attacker->x >= injured->x)
          ) &&
          injured_frame1->state == injured_state_2 &&
          is_attack_success != bool_false) {
        is_attack_success = bool_true;
      }
      if (itr->kind != itr_catch_injured &&
          itr->kind != itr_pick_up_weapon &&
          itr->kind != itr_rowing_pick &&
          is_attack_success != bool_false) {
        is_attack_success = bool_true;
      }
      if (itr->kind == itr_pick_up_weapon) {
        if (attacker->weapon_type == null &&
            attacker->click_attack &&
            !attacker->holding_attack &&
            injured_frame1->state == on_ground_state_1 &&
            is_attack_success != bool_false) {
          is_attack_success = bool_true;
        }
        if (attacker->click_attack &&
            !attacker->holding_attack &&
            injured_frame1->state == on_ground_state_2 &&
            is_attack_success != bool_false) {
          is_attack_success = bool_true;
        }
      }
      if ((itr->kind == itr_rowing_pick &&
           attacker->click_attack &&
           !attacker->holding_attack &&
           injured_frame1->state == on_ground_state_1 &&
           is_attack_success != bool_false
          ) ||
          is_attack_success == bool_true) {
        uint32_t attacks_size = attacker->successful_attacks;
        attacker->injured_of_attack[attacks_size] = injured_id;
        attacker->itr_of_attack[attacks_size] = itr_id;
        attacker->successful_attacks += 1;
      }
    }
  }
}

thiscall void
func_403270_teleport(global_t * global, uint32_t teleported_id, uint32_t teleport_to) {
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
    return;
  }
  object_t * teleported = global->objects[teleported_id];
  teleported->z_velocity = 0;
  teleported->x_velocity = 0;
  teleported->y_velocity = 0;
}
