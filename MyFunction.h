#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include "SphereInfo.h"

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

	Matrix4x4 MakeViewProjectionMatrix(const Matrix4x4& projectionMatrix, const Matrix4x4& viewMatrix);

	void GridDraw(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

	void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);


