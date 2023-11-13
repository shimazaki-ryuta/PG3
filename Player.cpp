#include "Player.h"
#include "matrixfunction.h"
#include "Novice.h"
#include "InputManager.h"
void Player::Initilalize() {
	position_ = {0,-100};
	radius_ = 25;
}

void Player::Update() {
	static float speed=2.0f;
	if (InputManager::PressKey(DIK_LEFT)) {
		position_.x -= speed;
	}
	if (InputManager::PressKey(DIK_RIGHT)) {
		position_.x += speed;
	}
	if (InputManager::PressKey(DIK_DOWN)) {
		position_.y -= speed;
	}
	if (InputManager::PressKey(DIK_UP)) {
		position_.y += speed;
	}
	if (InputManager::TriggerKey(DIK_SPACE)) {
		bulet_.reset(new Bulet);
		bulet_->Initilalize();
		bulet_->SetPosition(position_);
	}
	if (bulet_.get()) {
		bulet_->Update();
	}
}

void Player::Draw(Matrix3x3 vpVp) {
	Vector2 screenPosition = Transform(position_,vpVp);
	if (bulet_.get()) {
		bulet_->Draw(vpVp);
	}
	Novice::DrawEllipse(int(screenPosition.x), int(screenPosition.y),radius_,radius_,0,BLUE,kFillModeSolid);
}
