#include "Bulet.h"
#include "matrixfunction.h"
#include "Novice.h"
#include <cmath>
void Bulet::Initilalize() {
	position_ = { 0,100 };
	radius_ = 10;
	
}

void Bulet::Update() {
	static float speed = 5.0f;
	position_.y += speed;
}

void Bulet::Draw(Matrix3x3 vpVp) {
	Vector2 screenPosition = Transform(position_, vpVp);
	Novice::DrawEllipse(int(screenPosition.x), int(screenPosition.y), radius_, radius_, 0, BLUE, kFillModeSolid);
}
