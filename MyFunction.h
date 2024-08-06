#include "Matrix4x4.h"

#pragma once

class MyFunction {

public:

	MyFunction();

	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

	//加減
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

	//減算
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

	//スカラー倍
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	//逆行列
	Matrix4x4 Inverse(const Matrix4x4& m);

	//転置行列
	Matrix4x4 Transpose(const Matrix4x4& m);

	//単位行列
	Matrix4x4 MakeIdentity4x4();

	void Update();

	void Draw();

public:

	Matrix4x4 m1_;
	Matrix4x4 m2_;

	Matrix4x4 resultAdd_;

	Matrix4x4 resultSubtract_;

	Matrix4x4 resultMultiply_;

	Matrix4x4 inverseM1_;

	Matrix4x4 inverseM2_;

	Matrix4x4 transposeM1_;

	Matrix4x4 transposeM2_;

	Matrix4x4 identity_;

};

