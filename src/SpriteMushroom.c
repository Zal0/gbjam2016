#pragma bank=2
#include "SpriteMushroom.h"
UINT8 bank_SPRITE_MUSHROOM = 2;

#include "SpriteManager.h"
#include "../res/src/mushroom.h"

extern UINT8 mushroom_idx;
const UINT8 mushroom_anim_hide[] = {1, 0};
const UINT8 mushroom_anim_show[] = {1, 1};

#define NUM_CUSTOMS_DATA 5
struct MushroomCustomData {
	UINT8 time_out;
} mushroomCustomData[NUM_CUSTOMS_DATA];
DECLARE_STACK(mushroomCustomDataStack, NUM_CUSTOMS_DATA);

void MushroomResetCustomData() {
	UINT8 i;
	mushroomCustomDataStack[0] = 0;
	for(i = 0; i <NUM_CUSTOMS_DATA; ++i) {
		StackPush(mushroomCustomDataStack, i);
	}
}

void Start_SPRITE_MUSHROOM(struct Sprite* sprite) {
	struct MushroomCustomData* data;
	InitSprite(sprite, FRAME_16x16, mushroom_idx >> 2);
	SetSpriteAnim(sprite, mushroom_anim_hide, 3u);

	sprite->custom_data_idx = StackPop(mushroomCustomDataStack);
	data = &mushroomCustomData[sprite->custom_data_idx];
	data->time_out = 1u;
}

void Update_SPRITE_MUSHROOM() {
	struct MushroomCustomData* data = &mushroomCustomData[sprite_manager_current_sprite->custom_data_idx];
	
	data->time_out --;
	if(data->time_out == 0u) {
		data->time_out = 30u;
	}

	if(data->time_out > 15u) {
		SetSpriteAnim(sprite_manager_current_sprite, mushroom_anim_show, 3);
	} else {
		SetSpriteAnim(sprite_manager_current_sprite, mushroom_anim_hide, 3);
	}
}

void Destroy_SPRITE_MUSHROOM() {
	StackPush(mushroomCustomDataStack, sprite_manager_current_sprite->custom_data_idx);
}