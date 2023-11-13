#pragma once
#include "matrix.h"
#include "Bulet.h"
#include <memory>
class Player
{
public:
	void Initilalize();
	void Update();
	void Draw(Matrix3x3 vpVp);
	Bulet* GetBulet() { return bulet_.get(); };
private:
	Vector2 position_;
	int radius_;
	std::unique_ptr<Bulet> bulet_;
};

