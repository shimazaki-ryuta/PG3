#include<Novice.h>
#include "matrix.h"
#include <math.h>
#include <assert.h>

Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2)
{
	Matrix2x2 matrix;
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			matrix.m[row][column] = matrix1.m[row][column] + matrix2.m[row][column];
		}
	}
	return matrix;
}

Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2)
{
	Matrix2x2 matrix;
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			matrix.m[row][column] = matrix1.m[row][column] - matrix2.m[row][column];
		}
	}
	return matrix;
}

Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2)
{
	Matrix2x2 matrix;
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			matrix.m[row][column] = matrix1.m[row][0] * matrix2.m[0][column] + matrix1.m[row][1] * matrix2.m[1][column];
		}
	}
	return matrix;
}

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2)
{
	Matrix3x3 matrix;
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			matrix.m[row][column] = matrix1.m[row][0] * matrix2.m[0][column] + matrix1.m[row][1] * matrix2.m[1][column] + matrix1.m[row][2] * matrix2.m[2][column];
		}
	}
	return matrix;
}

Vector2 Multiply(Vector2 vector1, Matrix2x2 matrix2)
{
	Vector2 vector;
	Matrix2x2 matrix;
	for (int column = 0; column < 2; column++)
	{
		matrix.m[0][column] = vector1.x * matrix2.m[0][column] + vector1.y * matrix2.m[1][column];
	}
	vector.x = matrix.m[0][0];
	vector.y = matrix.m[0][1];
	return vector;
}

Matrix2x2 MakeRotateMatrix(float theta)
{
	Matrix2x2 matrix;
	matrix.m[0][0] = cosf(theta);
	matrix.m[0][1] = sinf(theta);
	matrix.m[1][0] = -1 * sinf(theta);
	matrix.m[1][1] = cosf(theta);


	return matrix;
}

Matrix3x3 MakeRotateMatrix3x3(float theta)
{
	Matrix3x3 matrix;
	matrix.m[0][0] = cosf(theta);
	matrix.m[0][1] = sinf(theta);
	matrix.m[0][2] = 0;
	matrix.m[1][0] = -1 * sinf(theta);
	matrix.m[1][1] = cosf(theta);
	matrix.m[1][2] = 0;
	matrix.m[2][0] = 0;
	matrix.m[2][1] = 0;
	matrix.m[2][2] = 1;
	return matrix;
}

Vector2 Transform(Vector2 vector, Matrix3x3 matrix)
{
	Vector2 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}

Matrix3x3 MakeTranslateMatrix(Vector2 translate)
{
	Matrix3x3 translatematrix;
	//translatematrix.m[0][0] = {{1,0,0},{0,1,0},{translate.x,translate.y,1}};
	translatematrix.m[0][0] = 1;
	translatematrix.m[0][1] = 0;
	translatematrix.m[0][2] = 0;
	translatematrix.m[1][0] = 0;
	translatematrix.m[1][1] = 1;
	translatematrix.m[1][2] = 0;
	translatematrix.m[2][0] = translate.x;
	translatematrix.m[2][1] = translate.y;
	translatematrix.m[2][2] = 1;
	return translatematrix;
}

Matrix3x3 MakeWorldMatrix(Vector2 scale, float theta, Vector2 translate)
{
	Matrix3x3 matrix;
	//scalematrix.m[0][0] = {{1,0,0},{0,1,0},{scale.x,scale.y,1}};
	matrix.m[0][0] = scale.x * cosf(theta);
	matrix.m[0][1] = scale.x * sinf(theta);
	matrix.m[0][2] = 0;
	matrix.m[1][0] = scale.y * -1 * sinf(theta);
	matrix.m[1][1] = scale.y * cosf(theta);
	matrix.m[1][2] = 0;
	matrix.m[2][0] = translate.x;
	matrix.m[2][1] = translate.y;
	matrix.m[2][2] = 1;
	return matrix;
}

Matrix2x2 Inverse(Matrix2x2 matrix)
{
	Matrix2x2 inverseMatrix;
	float determinant = (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]);
	Matrix2x2 adjugateMatrix;
	adjugateMatrix.m[0][0] = matrix.m[1][1];
	adjugateMatrix.m[0][1] = -matrix.m[0][1];
	adjugateMatrix.m[1][0] = -matrix.m[1][0];
	adjugateMatrix.m[1][1] = matrix.m[0][0];

	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			inverseMatrix.m[row][column] = (1 / determinant) * adjugateMatrix.m[row][column];
		}
	}
	return inverseMatrix;
}

Matrix3x3 Inverse(Matrix3x3 matrix)
{
	Matrix3x3 inverseMatrix;
	float determinant = (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2]) + (matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0]) + (matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1])
		- (matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0]) - (matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2]) - (matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);
	Matrix3x3 adjugateMatrix;
	adjugateMatrix.m[0][0] = (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]);
	adjugateMatrix.m[0][1] = -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]);
	adjugateMatrix.m[0][2] = (matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]);

	adjugateMatrix.m[1][0] = -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]);
	adjugateMatrix.m[1][1] = (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]);
	adjugateMatrix.m[1][2] = -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]);

	adjugateMatrix.m[2][0] = (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]);
	adjugateMatrix.m[2][1] = -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]);
	adjugateMatrix.m[2][2] = (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]);
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			inverseMatrix.m[row][column] = (1 / determinant) * adjugateMatrix.m[row][column];
		}
	}
	return inverseMatrix;
}

template<typename T>
T TransPose(T matrix)
{
	T transposeMatrix;
	for (int row = 0; row < (sizeof(transposeMatrix.m) / sizeof(transposeMatrix.m[0])); row++)
	{
		for (int column = 0; column < (sizeof(transposeMatrix.m[0]) / sizeof(transposeMatrix.m[0][0])); column++)
		{
			transposeMatrix.m[row][column] = matrix.m[column][row];
		}
	}
	return transposeMatrix;
}

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom)
{
	Matrix3x3 orthoMatrix;
	orthoMatrix.m[0][0] = 2.0f / (right - left);
	orthoMatrix.m[0][1] = 0;
	orthoMatrix.m[0][2] = 0;
	orthoMatrix.m[1][0] = 0;
	orthoMatrix.m[1][1] = 2.0f / (top - bottom);
	orthoMatrix.m[1][2] = 0;
	orthoMatrix.m[2][0] = (left + right) / (left - right);
	orthoMatrix.m[2][1] = (top + bottom) / (bottom - top);
	orthoMatrix.m[2][2] = 1;
	return orthoMatrix;
}

Matrix3x3 MakeViewPortMatrix(float left, float top, float width, float height)
{
	Matrix3x3 viewPortMatrix;
	viewPortMatrix.m[0][0] = width / 2.0f;
	viewPortMatrix.m[0][1] = 0;
	viewPortMatrix.m[0][2] = 0;
	viewPortMatrix.m[1][0] = 0;
	viewPortMatrix.m[1][1] = -height / 2.0f;
	viewPortMatrix.m[1][2] = 0;
	viewPortMatrix.m[2][0] = left + (width / 2.0f);
	viewPortMatrix.m[2][1] = top + (height / 2.0f);
	viewPortMatrix.m[2][2] = 1;
	return viewPortMatrix;

}

void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix)
{
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}

void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix)
{
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}

void VectorScreenPrintf(int x, int y, Vector2 vector)
{
	Novice::ScreenPrintf(x, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%6.02f", vector.y);
}

Matrix3x3 operator*(const Matrix3x3& m1, const Matrix3x3& m2) { return Multiply(m1, m2); }