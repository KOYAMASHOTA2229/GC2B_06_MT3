#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"

struct Affine
{
	Vector3 scale;

	Vector3 rotate;

	Vector3 translate;
};

class MyFunction {

public:

	MyFunction();

	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	Matrix4x4 MakeRotateXMatrix(float radian);

	Matrix4x4 MakeRotateYMatrix(float radian);

	Matrix4x4 MakeRotateZMatrix(float radian);

	Matrix4x4 MakeScaleMatrix(const Vector3& scale);

	Matrix4x4 MakeRotateMatrix(const Vector3& radian);

	Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

	Matrix4x4 MakeAffineMatrix(Affine affine);

	void Update();

	void Draw();

public:

	Matrix4x4 rotateXMatrix_;

	Matrix4x4 rotateYMatrix_;

	Matrix4x4 rotateZMatrix_;

	Matrix4x4 rotateXYZMatrix_;

	Affine affine_;

	Matrix4x4 worldMatrix_;

};