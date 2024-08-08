#pragma once
#include "Matrix4x4.h"

class MyFunction {

public:

	MyFunction();

	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

	Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

	Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

	void Update();

	void Draw();

public:

	Matrix4x4 orthographicMatrix_;

	Matrix4x4 perspectiveFovMatrix_;

	Matrix4x4 viewportMatrix_;

};