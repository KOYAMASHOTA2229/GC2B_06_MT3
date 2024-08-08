#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"

class MyFunction {

public:

	MyFunction();

	void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

	Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

	Matrix4x4 MakeScaleMatrix(const Vector3& scale);

	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

	void Update();

	void Draw();

public:

	Matrix4x4 translateMatrix_;

	Matrix4x4 scaleMatrix_;

	Matrix4x4 transformMatrix_;

	Vector3 translate_;

	Vector3 scale_;

	Vector3 point_;

	Vector3 transformed_;

};