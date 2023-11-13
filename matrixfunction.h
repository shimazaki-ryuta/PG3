#pragma once
#include "matrix.h"
#include <math.h>
#include <assert.h>

void MatrixScreenPrintf(int, int, Matrix2x2);
void MatrixScreenPrintf(int, int, Matrix3x3);
void VectorScreenPrintf(int, int, Vector2);

Matrix2x2 Add(Matrix2x2 matrix1, Matrix2x2 matrix2);

Matrix2x2 Subtract(Matrix2x2 matrix1, Matrix2x2 matrix2);

Matrix2x2 Multiply(Matrix2x2 matrix1, Matrix2x2 matrix2);

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);

Vector2 Multiply(Vector2 vector1, Matrix2x2 matrix2);

Matrix2x2 MakeRotateMatrix(float theta);

Matrix3x3 MakeRotateMatrix3x3(float theta);

Vector2 Transform(Vector2 vector, Matrix3x3 matrix);

Matrix3x3 MakeTranslateMatrix(Vector2 translate);

Matrix3x3 MakeWorldMatrix(Vector2 scale, float theta, Vector2 translate);

Matrix2x2 Inverse(Matrix2x2 matrix);

Matrix3x3 Inverse(Matrix3x3 matrix);

template<typename T>
T TransPose(T matrix);

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);

Matrix3x3 MakeViewPortMatrix(float left, float top, float width, float height);

Matrix3x3 operator*(const Matrix3x3& m1, const Matrix3x3& m2);