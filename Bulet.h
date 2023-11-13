#pragma once
#include "matrix.h"
class Bulet
{
public:
	void Initilalize();
	void Update();
	void Draw(Matrix3x3 vpVp);
	void SetPosition(const Vector2& position) { position_ = position; };
	Vector2 GetPosition() { return position_; };
	int GetRadius() { return radius_; };
private:
	Vector2 position_;
	int radius_;
};

