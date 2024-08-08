#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include "SphereInfo.h"

class MyFunction {

public:

	MyFunction();

	void TranslateMove(char* keys);

	void RotateMove();

	void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* lebel);

	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	Matrix4x4 MakeScaleMatrix(const Vector3& scale);

	Matrix4x4 MakeRotateXMatrix(float radian);

	Matrix4x4 MakeRotateYMatrix(float radian);

	Matrix4x4 MakeRotateZMatrix(float radian);

	Matrix4x4 MakeRotateMatrix(const Vector3& radian);

	Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

	Matrix4x4 Inverse(const Matrix4x4& m);

	Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

	Vector3 Cross(const Vector3& v1, const Vector3& v2);

	void Update(char* keys);

	void Draw();

private:

	Matrix4x4 worldMatrix_;

	Matrix4x4 cameraMatrix_;

	Matrix4x4 viewMatrix_;

	Matrix4x4 projectionMatrix_;

	Matrix4x4 worldViewProjectionMatrix_;

	Matrix4x4 viewportMatrix_;

	Vector3 v1_;

	Vector3 v2_;

	Vector3 cross_;

	Vector3 rotate_;

	Vector3 translate_;

	Vector3 cameraPosition_;

	Vector3 ndcVertex_;

	Vector3 kLocalVertices_[3];

	Vector3 screenVertices_[3];

	Vector3 translateSpeed_;

	float rotateSpeed_;

};