#pragma once
#include "matrix.h"
class Enemy
{
public:
	void Initilalize();
	void Update();
	void Draw(Matrix3x3 vpVp);
	void SetIsDead(bool is) { isDead_ = is; };
	bool GetIsDead() { return isDead_; };
	Vector2 GetPosition() { return position_; };
	int GetRadius() { return radius_; };
private:
	Vector2 position_;
	int radius_;
	float theta_;
	bool isDead_;
};

