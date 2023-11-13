#include "Enemy.h"
#include "matrixfunction.h"
#include "Novice.h"
#include <cmath>
void Enemy::Initilalize() {
	position_ = { 0,100 };
	radius_ = 25;
	theta_ = 0;
	isDead_ = false;
}

void Enemy::Update() {
	static float speed = 2.0f;
	static float width = 200;
	position_.x = std::sin(theta_) * width;
	theta_ += 0.02f;
}

void Enemy::Draw(Matrix3x3 vpVp) {
	Vector2 screenPosition = Transform(position_, vpVp);
	Novice::DrawEllipse(int(screenPosition.x), int(screenPosition.y), radius_, radius_, 0, RED, kFillModeSolid);
}
