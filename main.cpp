#include <Novice.h>
#include "MyFunction.h"
#include "imgui.h"

const char kWindowTitle[] = "GC2B_06_コヤマ_ショウタ";

static inline const float kWindowWidth = 1280.0f;
static inline const float kWindowHeight = 720.0f;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 translate = {};
	Vector3 rotate = {};

	//カメラ位置
	Vector3 cameraTranslate{ 0.0f,1.9f,-6.49f };
	//カメラ角度
	Vector3 cameraRotate{ 0.26f,0.0f,0.0f };

	Vector3 cameraScale{ 1.0f,1.0f,1.0f };

	Sphere sphere = {
		{0.0f,0.0f,0.0f},
		0.5f
	};

	uint32_t color = BLACK;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);

		Matrix4x4 cameraWorldMatrix = MakeAffineMatrix(cameraScale, cameraRotate, cameraTranslate);

		Matrix4x4 viewMatrix = Inverse(cameraWorldMatrix);

		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, kWindowWidth / kWindowHeight, 0.1f, 100.0f);

		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, kWindowWidth, kWindowHeight, 0.0f, 1.0f);
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		ImGui::Begin("DebugWindow");

		ImGui::DragFloat3("cameraTranslate", &cameraTranslate.x, 0.01f);

		ImGui::DragFloat3("cameraRotate", &cameraRotate.x, 0.01f);

		ImGui::DragFloat3("SphereCenter", &sphere.center.x, 0.01f);

		ImGui::DragFloat("SphereRadius", &sphere.radius, 0.01f);

		ImGui::End();

		GridDraw(worldViewProjectionMatrix, viewportMatrix);
		DrawSphere(sphere, worldViewProjectionMatrix, viewportMatrix, color);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
