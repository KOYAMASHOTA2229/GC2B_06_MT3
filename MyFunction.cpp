#include "MyFunction.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>


static const int kRowHeight = 20;
static const int kColumnWidth = 60;

float cot(float x)
{
	return 1.0f / tanf(x);
}

MyFunction::MyFunction() {

	orthographicMatrix_ = {};

	perspectiveFovMatrix_ = {};

	viewportMatrix_ = {};

}

void MyFunction::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label)
{
	Novice::ScreenPrintf(x, y, label);

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight + 20, "%6.02f", matrix.m[row][column]);
		}
	}
}

Matrix4x4 MyFunction::MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip){

	Matrix4x4 resultPerspectiveFov = {
		1.0f / aspectRatio * cot(fovY / 2.0f),0.0f,0.0f,0.0f,
		0.0f,cot(fovY / 2.0f),0.0f,0.0f,
		0.0f,0.0f,farClip / (farClip - nearClip),1.0f,
		0.0f,0.0f,-nearClip * farClip / (farClip - nearClip),0.0f

	};

	return resultPerspectiveFov;
}

Matrix4x4 MyFunction::MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip){

	Matrix4x4 resultOrthographic = {
		2.0f / (right - left),0.0f,0.0f,0.0f,
		0.0f,2.0f / (top - bottom),0.0f,0.0f,
		0.0f,0.0f,1.0f / (farClip - nearClip),0.0f,
		(left + right) / (left - right),(top + bottom) / (bottom - top),nearClip / (nearClip - farClip),1.0f

	};

	return resultOrthographic;
}

Matrix4x4 MyFunction::MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth){

	Matrix4x4 resultViewport = {
		width / 2.0f,0.0f,0.0f,0.0f,
		0.0f,-height / 2.0f,0.0f,0.0f,
		0.0f,0.0f,maxDepth - minDepth,0.0f,
		left + width / 2.0f,top + height / 2.0f,minDepth,1.0f

	};
	return resultViewport;
}

void MyFunction::Update() {

	orthographicMatrix_ = MakeOrthographicMatrix(-160.f, 160.f, 200.0f, 300.0f, 0.0f,
		1000.0f);
	perspectiveFovMatrix_ = MakePerspectiveFovMatrix(0.63f, 1.33f, 0.1f, 1000.0f);

	viewportMatrix_ = MakeViewportMatrix(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);

}

void MyFunction::Draw() {

	MatrixScreenPrintf(0, 0, orthographicMatrix_, "orthographicMatrix");

	MatrixScreenPrintf(0, kRowHeight * 5, perspectiveFovMatrix_, "perspectiveFovMatrix");

	MatrixScreenPrintf(0, kRowHeight * 10, viewportMatrix_, "viewportMatrix");

}