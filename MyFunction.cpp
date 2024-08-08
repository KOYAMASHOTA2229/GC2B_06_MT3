#include "MyFunction.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

MyFunction::MyFunction() {

	rotate_ = { 0.4f,1.43f,-0.8f };

	rotateXMatrix_ = {};

	rotateYMatrix_ = {};

	rotateZMatrix_ = {};

	rotateXYZMatrix_ = {};

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

void MyFunction::Update() {

	rotateXMatrix_ = MakeRotateXMatrix(rotate_.x);

	rotateYMatrix_ = MakeRotateYMatrix(rotate_.y);

	rotateZMatrix_ = MyFunction::MakeRotateZMatrix(rotate_.z);

	rotateXYZMatrix_ = Multiply(rotateXMatrix_, Multiply(rotateYMatrix_, rotateZMatrix_));

}

void MyFunction::Draw() {

	MatrixScreenPrintf(0, 0, rotateXMatrix_, "rotateXMatrix");

	MatrixScreenPrintf(0, kRowHeight * 5, rotateYMatrix_, "rotateYMatrix");

	MatrixScreenPrintf(0, kRowHeight * 5 * 2, rotateZMatrix_, "rotateZMatrix");

	MatrixScreenPrintf(0, kRowHeight * 5 * 3, rotateXYZMatrix_, "rotateXYZMatrix");

}