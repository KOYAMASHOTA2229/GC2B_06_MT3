#include "MyFunction.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

MyFunction::MyFunction() {

	translate_ = { 4.1f,2.6f,0.8f };

	scale_ = { 1.5f,5.2f,7.3f };

	translateMatrix_ = {};

	scaleMatrix_ = {};

	point_ = { 2.3f,3.8f,1.4f };


	transformMatrix_ = {
		1.0f,2.0f,3.0f,4.0f,
		3.0f,1.0f,1.0f,2.0f,
		1.0f,4.0f,2.0f,3.0f,
		2.0f,2.0f,1.0f,3.0f,
	};

	transformed_ = {};

}

void MyFunction::VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {

	Novice::ScreenPrintf(x, y, "%.02f", vector.x);

	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);

	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);

	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);

}

void MyFunction::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {

	Novice::ScreenPrintf(x, y + 20, label);

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight + 40, "%6.02f", matrix.m[row][column]);
		}
	}


}

Matrix4x4 MyFunction::MakeTranslateMatrix(const Vector3& translate) {

	Matrix4x4 resultTranslate = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		translate.x,translate.y,translate.z,1.0f
	};

	return resultTranslate;

}

Matrix4x4 MyFunction::MakeScaleMatrix(const Vector3& scale) {

	Matrix4x4 resultScale = {
		scale.x,0.0f,0.0f,0.0f,
		0.0f,scale.y,0.0f,0.0f,
		0.0f,0.0f,scale.z,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};

	return resultScale;

}

Vector3 MyFunction::Transform(const Vector3& vector, const Matrix4x4& matrix) {

	Vector3 result;

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + matrix.m[3][0];

	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + matrix.m[3][1];

	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + matrix.m[3][2];

	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + matrix.m[3][3];

	assert(w != 0.0f);

	result.x /= w;

	result.y /= w;

	result.z /= w;

	return result;

}

void MyFunction::Update() {

	translateMatrix_ = MakeTranslateMatrix(translate_);

	scaleMatrix_ = MakeScaleMatrix(scale_);

	transformed_ = Transform(point_, transformMatrix_);

}

void MyFunction::Draw() {

	VectorScreenPrintf(0, 0, transformed_, "transformed");

	MatrixScreenPrintf(0, 0, translateMatrix_, "translateMatrix");

	MatrixScreenPrintf(0, kRowHeight * 5, scaleMatrix_, "scaleMatrix");

}