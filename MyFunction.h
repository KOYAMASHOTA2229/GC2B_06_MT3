#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"

class MyFunction {

public:

	MyFunction();

	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	Matrix4x4 MakeRotateXMatrix(float radian);

	Matrix4x4 MakeRotateYMatrix(float radian);

	Matrix4x4 MakeRotateZMatrix(float radian);

	void Update();

	void Draw();

public:

	Vector3 rotate_;

	Matrix4x4 rotateXMatrix_;

	Matrix4x4 rotateYMatrix_;

	Matrix4x4 rotateZMatrix_;

	Matrix4x4 rotateXYZMatrix_;

};