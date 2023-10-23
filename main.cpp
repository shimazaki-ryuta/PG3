#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
class IShape
{
public:
	
	virtual void Size()=0;
	virtual void Draw() = 0;
};

class Circle : public IShape
{
public:
	Circle(float radius) {
		radius_ = radius;
	}
	void Size() override {
		size_ = float(M_PI) * radius_ * radius_;
	};
	void Draw() override {
		printf("%f\n",size_);
	};
private:
	float size_;
	float radius_;
};

class Rectangle : public IShape
{
public:
	Rectangle(float width,float height) {
		width_ = width;
		height_ = height;
	};
	void Size() override {
		size_ = width_ * height_;
	};
	void Draw() override {
		printf("%f\n", size_);
	}; 
private:
	float size_;
	float width_;
	float height_;
};

int main() {
	IShape* shapes[2];
	shapes[0] = new Circle(2.0f);
	shapes[1] = new Rectangle(1.0f,1.0f);
	for (IShape* shape : shapes) {
		shape->Size();
		shape->Draw();
	}
	
	for (IShape* shape : shapes) {
		delete shape;
	}

	return 0;
}