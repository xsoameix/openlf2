#include <stdint.h>
#include "const.h"

const struct global * global           = (void *) 0x458B00;

const uint32_t template_dat            =   0;
const uint32_t julian_dat              =  52;
const uint32_t firzen_dat              =  51;
const uint32_t louisEX_dat             =  50;
const uint32_t bat_dat                 =  38;
const uint32_t justin_dat              =  39;
const uint32_t knight_dat              =  37;
const uint32_t jan_dat                 =  36;
const uint32_t monk_dat                =  35;
const uint32_t sorcerer_dat            =  34;
const uint32_t jack_dat                =  33;
const uint32_t mark_dat                =  32;
const uint32_t hunter_dat              =  31;
const uint32_t bandit_dat              =  30;
const uint32_t deep_dat                =   1;
const uint32_t john_dat                =   2;
const uint32_t henry_dat               =   4;
const uint32_t rudolf_dat              =   5;
const uint32_t louis_dat               =   6;
const uint32_t firen_dat               =   7;
const uint32_t freeze_dat              =   8;
const uint32_t dennis_dat              =   9;
const uint32_t woody_dat               =  10;
const uint32_t davis_dat               =  11;
const uint32_t stick_dat               = 100;
const uint32_t hoe_dat                 = 101;
const uint32_t knife_dat               = 120;
const uint32_t baseball_dat            = 121;
const uint32_t milk_dat                = 122;
const uint32_t stone_dat               = 150;
const uint32_t wooden_box_dat          = 151;
const uint32_t beer_dat                = 123;
const uint32_t boomerang_dat           = 124;
const uint32_t louis_wrister_dat       = 217;
const uint32_t louis_armour_dat        = 218;
const uint32_t criminal_dat            = 300;
const uint32_t john_ball_dat           = 200;
const uint32_t henry_arrow1_dat        = 201;
const uint32_t rudolf_weapon_dat       = 202;
const uint32_t deep_ball_dat           = 203;
const uint32_t henry_wind_dat          = 204;
const uint32_t dennis_ball_dat         = 205;
const uint32_t woody_ball_dat          = 206;
const uint32_t davis_ball_dat          = 207;
const uint32_t henry_arrow2_dat        = 208;
const uint32_t freeze_ball_dat         = 209;
const uint32_t firen_ball_dat          = 210;
const uint32_t firen_flame_dat         = 211;
const uint32_t freeze_column_dat       = 212;
const uint32_t ice_sword_dat           = 213;
const uint32_t john_biscuit_dat        = 214;
const uint32_t dennis_chase_dat        = 215;
const uint32_t jack_ball_dat           = 216;
const uint32_t jan_chaseh_dat          = 219;
const uint32_t jan_chase_dat           = 220;
const uint32_t firzen_chasef_dat       = 221;
const uint32_t firzen_chasei_dat       = 222;
const uint32_t firzen_ball_dat         = 223;
const uint32_t bat_ball_dat            = 224;
const uint32_t bat_chase_dat           = 225;
const uint32_t justin_ball_dat         = 226;
const uint32_t julian_ball_dat         = 228;
const uint32_t julian_ball2_dat        = 229;
const uint32_t etc_dat                 = 998;
const uint32_t broken_weapon_dat       = 999;

const uint32_t character_type          = 0;
const uint32_t lignt_weapon_type       = 1;
const uint32_t heavy_weapon_type       = 2;
const uint32_t attack_type             = 3;
const uint32_t throw_weapon_type       = 4;
const uint32_t criminal_type           = 5;
const uint32_t drink_type              = 6;

const uint32_t in_the_sky_frame        =  0;
const uint32_t hitting_frame           = 10;

const uint8_t facing_right             = 0;
const uint8_t facing_left              = 1;

const uint8_t null                     = 0;

const uint8_t bool_initial             = 0;
const uint8_t bool_true                = 1;
const uint8_t bool_false               = 2;

const uint32_t jump_state              = 4;
const uint32_t dash_state              = 5;
const uint32_t defend_state            = 7;
const uint32_t broken_defend_state     = 8;
const uint32_t catching_state          = 9;
const uint32_t picked_caught_state     = 10;
const uint32_t injured_state_1         = 11;
const uint32_t falling_state           = 12;
const uint32_t ice_state               = 13;
const uint32_t lying_state             = 14;
const uint32_t injured_state_2         = 16;
const uint32_t fire_state              = 18;
const uint32_t burn_run_state          = 19;
const uint32_t teleport_to_enemy_state = 400;
const uint32_t teleport_to_team_state  = 401;
const uint32_t in_the_sky_state_1      = 1000;
const uint32_t throwing_state          = 1002;
const uint32_t on_ground_state_1       = 1004;
const uint32_t in_the_sky_state_2      = 2000;
const uint32_t on_ground_state_2       = 2004;

const uint32_t freeze_frame_start      = 200;
const uint32_t freeze_frame_end        = 202;
const uint32_t slightly_injured_frame  = 220;
const uint32_t front_injured_frame     = 222;
const uint32_t back_injured_frame      = 224;

const uint32_t itr_normal_attack       = 0;
const uint32_t itr_catch_injured       = 1;
const uint32_t itr_pick_up_weapon      = 2;
const uint32_t itr_catch               = 3;
const uint32_t itr_thrown              = 4;
const uint32_t itr_strength_list       = 5;
const uint32_t itr_super_punch         = 6;
const uint32_t itr_rowing_pick         = 7;
const uint32_t itr_heal                = 8;
const uint32_t itr_forcefield          = 9;
const uint32_t itr_flute               = 10;
const uint32_t itr_float               = 11;
const uint32_t itr_stop                = 14;
const uint32_t itr_fly                 = 15;
const uint32_t itr_freeze              = 16;

const uint32_t punch_effect            = 0;
const uint32_t bleed_effect            = 1;
const uint32_t fire_type_effect        = 2; // means effect % 10 == 2
const uint32_t fire_effect             = 2;
const uint32_t burn_effect             = 20;
const uint32_t flame_effect            = 21;
const uint32_t firen_explosion_effect  = 22;
const uint32_t julian_explosion_effect = 23;
const uint32_t freeze_type_effect      = 3; // means effect % 10 == 3
const uint32_t freeze_effect           = 3;
const uint32_t column_effect           = 30;
const uint32_t shrafe_effect           = 4;

const uint32_t teleport_to_enemy       = 1;
const uint32_t teleport_to_team        = 2;

const uint32_t max_objects_size        = 400;

const uint32_t no_team                 = 0;
const uint32_t team_1                  = 1;
const uint32_t team_2                  = 2;
const uint32_t team_3                  = 3;
const uint32_t team_4                  = 4;
const uint32_t stage_enemy_team        = 5;
const uint32_t player_1_team           = 10;
const uint32_t player_2_team           = 11;
const uint32_t player_3_team           = 12;
const uint32_t player_4_team           = 13;
const uint32_t computer_1_team         = 20;
const uint32_t computer_2_team         = 21;
const uint32_t computer_3_team         = 22;
const uint32_t computer_4_team         = 23;
const uint32_t computer_5_team         = 24;
const uint32_t computer_6_team         = 25;
const uint32_t computer_7_team         = 26;
const uint32_t computer_8_team         = 27;

const uint32_t vs_mode                 = 0;
const uint32_t stage_mode              = 1;
const uint32_t champion_1_on_1_mode    = 2;
const uint32_t champion_2_on_2_mode    = 3;
const uint32_t battle_mode             = 4;
const uint32_t demo_mode               = 5;
const uint32_t playback_recoding_mode  = 6;
const uint32_t quit_mode               = 7;
