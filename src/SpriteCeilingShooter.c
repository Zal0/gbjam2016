#include "Banks/SetBank2.h"
#include "main.h"

#include "../res/src/ceilingshooter.h"
#include "SpriteManager.h"

void CreateEnemyBullet(UINT16 x, UINT16 y, INT8 vx, INT8 vy);

struct CShooterCustomData {
	UINT8 cool_down;
};

void Start_SpriteCeilingShooter() { 
	struct CShooterCustomData* data = (struct CShooterCustomData*)THIS->custom_data;

	data->cool_down = 70;
}

void Update_SpriteCeilingShooter() {
	struct CShooterCustomData* data = (struct CShooterCustomData*)THIS->custom_data;
	
	data->cool_down += 1 << delta_time;
	if(data->cool_down > 70) {
		CreateEnemyBullet(THIS->x + 4, THIS->y, 0, 1);
		data->cool_down = 0;
	}

	if(data->cool_down < 10u) {
		SET_FRAME(THIS, (UINT8)1u);
	} else {
		SET_FRAME(THIS, (UINT8)0u);
	}
}

void Destroy_SpriteCeilingShooter() { 
}