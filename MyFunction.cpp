#include "MyFunction.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

MyFunction::MyFunction() {


	rotateXMatrix_ = {};

	rotateYMatrix_ = {};

	rotateZMatrix_ = {};

	rotateXYZMatrix_ = {};

	affine_ = {
		{ 1.2f,0.79f,-2.1f },
		{ 0.4f,1.43f,-0.8f },
		{ 2.7f,-4.15f,1.57f }
	};

}

void MyFunction::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {

	Novice::ScreenPrintf(x, y, label);

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight + 20, "%6.02f", matrix.m[row][column]);
		}
	}


}

Matrix4x4 MyFunction::Multiply(const Matrix4x4& m1, const Matrix4x4& m2)
{
	Matrix4x4 MultiplyMatrix{};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			MultiplyMatrix.m[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				MultiplyMatrix.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}

	return MultiplyMatrix;
}

Matrix4x4 MyFunction::MakeRotateXMatrix(float radian) {

	Matrix4x4 rotateXMatrix = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,std::cos(radian),std::sin(radian),0.0f,
		0.0f,-std::sin(radian),std::cos(radian),0.0f,
		0.0f,0.0f,0.0f,1.0f

	};

	return rotateXMatrix;

}

Matrix4x4 MyFunction::MakeRotateYMatrix(float radian) {

	Matrix4x4 rotateYMatrix = {
		std::cos(radian),0.0f,-std::sin(radian),0.0f,
		0.0f,1.0f,0.0f,0.0f,
		std::sin(radian),0.0f,std::cos(radian),0.0f,
		0.0f,0.0f,0.0f,1.0f
	};

	return rotateYMatrix;

}

Matrix4x4 MyFunction::MakeRotateZMatrix(float radian) {

	Matrix4x4 rotateZMatrix = {
		std::cos(radian),std::sin(radian),0.0f,0.0f,
		-std::sin(radian),std::cos(radian),0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};

	return rotateZMatrix;

}

Matrix4x4 MyFunction::MakeScaleMatrix(const Vector3& scale){

	Matrix4x4 resultScale = {
		scale.x,0.0f,0.0f,0.0f,
		0.0f,scale.y,0.0f,0.0f,
		0.0f,0.0f,scale.z,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	return resultScale;
}

Matrix4x4 MyFunction::MakeRotateMatrix(const Vector3& radian){

	return Multiply(MakeRotateXMatrix(radian.x), Multiply(MakeRotateYMatrix(radian.y), MakeRotateZMatrix(radian.z)));

}

Matrix4x4 MyFunction::MakeTranslateMatrix(const Vector3& translate){

	Matrix4x4 resultTranslate = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		translate.x,translate.y,translate.z,1.0f
	};
	return resultTranslate;
}

Matrix4x4 MyFunction::MakeAffineMatrix(Affine affine){

	return Multiply(Multiply(MakeScaleMatrix(affine.scale), MakeRotateMatrix(affine.rotate)), MakeTranslateMatrix(affine.translate));

}

void MyFunction::Update() {

	worldMatrix_ = MyFunction::MakeAffineMatrix(affine_);

}

void MyFunction::Draw() {

	MyFunction::MatrixScreenPrintf(0, 0, worldMatrix_, "worldMatrix");

}