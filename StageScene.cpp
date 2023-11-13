#include "StageScene.h"
#include "Novice.h"
#include "InputManager.h"
#include "matrixfunction.h"
#include <math.h>
void StageScene::Initialize() {
	sceneNo = STAGE;
	Matrix3x3 camera = MakeWorldMatrix({ 1,1 }, 0, { 0,0 });
	Matrix3x3 view = Inverse(camera);
	Matrix3x3 ortho = MakeOrthographicMatrix(-640, 360, 640, -360);
	Matrix3x3 viewPort = MakeViewPortMatrix(0, 0, 1280, 720);

	vpVp_ = view * ortho * viewPort;

	player_.reset(new Player);
	player_->Initilalize();

	enemy_.reset(new Enemy);
	enemy_->Initilalize();

}
void StageScene::Update() {
	player_->Update();
	enemy_->Update();
	Bulet* bulet = player_->GetBulet();
	if (bulet && !enemy_->GetIsDead()) {
		float distance = sqrtf(powf(bulet->GetPosition().x - enemy_->GetPosition().x, 2) +
			powf(bulet->GetPosition().y - enemy_->GetPosition().y, 2));
		if (distance < float(bulet->GetRadius() + enemy_->GetRadius())) {
			sceneNo = CLEAR;
			enemy_->SetIsDead(true);
		}
	}
}
void StageScene::Draw() {
	Novice::ScreenPrintf(20, 20, "GAMESCENE");
	player_->Draw(vpVp_);
	if (!enemy_->GetIsDead()) {
		enemy_->Draw(vpVp_);
	}
}