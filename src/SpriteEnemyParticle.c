#include "Banks/SetBank2.h"
#include "main.h"

#include "../res/src/enemyexplosion.h"
#include "SpriteManager.h"

const UINT8 eparticle_anim[] = {5, 0, 1, 2, 3, 3};

void Start_SpriteEnemyParticle() {
	SetSpriteAnim(THIS, eparticle_anim, 33);
}

void Update_SpriteEnemyParticle() {
	if(THIS->anim_frame == 4) {
		SpriteManagerRemove(THIS_IDX);
	}
}

void Destroy_SpriteEnemyParticle () {
}