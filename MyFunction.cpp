#include "MyFunction.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include<cmath>

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

MyFunction::MyFunction() {
#pragma region

	v1_ = { 1.0f,3.0f,-5.0f };
	v2_ = { 4.0f,-1.0f,2.0f };

	k_ = { 4.0f };

	resultAdd_ = {};

	resultSubtract_ = {};

	resultMultiply_ = {};

	resultDot_ = {};

	resultLength_ = {};

	resultNormalize_ = {};

#pragma endregion
}


void MyFunction::VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

Vector3 MyFunction::Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 resultAdd = { v1.x + v2.x,v1.y + v2.y,v1.z + v2.z };
	return resultAdd;
}

Vector3 MyFunction::Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 resultSubtract = { v1.x - v2.x,v1.y - v2.y,v1.z - v2.z };
	return resultSubtract;
}

Vector3 MyFunction::Multiply(float scalar, const Vector3& v2)
{
	Vector3 resultMultiply = { scalar * v2.x ,scalar * v2.y,scalar * v2.z };
	return resultMultiply;
}

float MyFunction::Dot(const Vector3& v1, const Vector3& v2)
{
	float resultDot = { v1.x * v2.x + v1.y * v2.y + v1.z * v2.z };
	return resultDot;
}

float MyFunction::Length(const Vector3& v)
{
	float result = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return result;
}

Vector3 MyFunction::Normalize(const Vector3& v)
{
	float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	Vector3 resultNormalize = { v.x,v.y,v.z };

	if (length != 0.0f) {
		resultNormalize = { v.x / length,v.y / length,v.z / length };
	}
	return resultNormalize;
}

void MyFunction::Update() {
	resultAdd_ = MyFunction::Add(v1_, v2_);
	resultSubtract_ = MyFunction::Subtract(v1_, v2_);
	resultMultiply_ = MyFunction::Multiply(k_, v1_);
	resultDot_ = MyFunction::Dot(v1_, v2_);
	resultLength_ = MyFunction::Length(v1_);
	resultNormalize_ = MyFunction::Normalize(v2_);
}

void MyFunction::Draw() {
	MyFunction::VectorScreenPrintf(0, 0, resultAdd_, " : Add");
	MyFunction::VectorScreenPrintf(0, kRowHeight, resultSubtract_, " : Subtract");
	MyFunction::VectorScreenPrintf(0, kRowHeight * 2, resultMultiply_, " : Multiply");
	Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f : Dot", resultDot_);
	Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f : Length", resultLength_);
	MyFunction::VectorScreenPrintf(0, kRowHeight * 5, resultNormalize_, " :  Normalize");
}