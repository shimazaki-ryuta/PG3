#include "SceneManager.h"
#include "InputManager.h"
#include "Novice.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include <functional>
//SceneManager::sceneTable;

SceneManager::SceneManager(){
	sceneTable[0] = std::make_unique<TitleScene>();
	sceneTable[1] = std::make_unique<StageScene>();
	sceneTable[2] = std::make_unique<ClearScene>();
	sceneTable[0]->Initialize();
	//scene = std::make_unique<TitleScene>();
	//scene->Initialize();
	currentSceneNo_ = TITLE;
	nextSceneNo_ = currentSceneNo_;
}

SceneManager::~SceneManager() {

}

int SceneManager::Run() {
	while (Novice::ProcessMessage()==0) {
		// フレームの開始
		Novice::BeginFrame();
		InputManager::GetInstance()->Update();
		if (nextSceneNo_ != sceneTable[currentSceneNo_]->GetSceneNo()) {
			nextSceneNo_ = sceneTable[currentSceneNo_]->GetSceneNo();
			isLoadEnd_ = false;
			loadNextScene = std::thread(std::bind(&SceneManager::LoadNextScene,this));
		}
		if (nextSceneNo_ != currentSceneNo_) {
			if (isLoadEnd_) {
				loadNextScene.detach();
				currentSceneNo_ = nextSceneNo_;
			}
		}


		sceneTable[currentSceneNo_]->Update();
		sceneTable[currentSceneNo_]->Draw();
	
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::TriggerKey(DIK_ESCAPE)) {
			loadNextScene.join();
			break;
		}
	}
	return 0;
}

void SceneManager::LoadNextScene() {
	isLoadEnd_ = false;
	sceneTable[nextSceneNo_]->Initialize();
	//初期化処理の時間(擬似)
	Sleep(2000);
	isLoadEnd_ = true;
}