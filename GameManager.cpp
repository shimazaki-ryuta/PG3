#include "GameManager.h"
#include "InputManager.h"
#include "Novice.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include <functional>
//GameManager::sceneTable;

GameManager::GameManager(){
	sceneTable[0] = std::make_unique<TitleScene>();
	sceneTable[1] = std::make_unique<StageScene>();
	sceneTable[2] = std::make_unique<ClearScene>();
	sceneTable[0]->Initialize();
	//scene = std::make_unique<TitleScene>();
	//scene->Initialize();
	currentSceneNo_ = TITLE;
	nextSceneNo_ = currentSceneNo_;
}

GameManager::~GameManager() {

}

int GameManager::Run() {
	while (Novice::ProcessMessage()==0) {
		// フレームの開始
		Novice::BeginFrame();
		InputManager::GetInstance()->Update();
		if (nextSceneNo_ != sceneTable[currentSceneNo_]->GetSceneNo()) {
			nextSceneNo_ = sceneTable[currentSceneNo_]->GetSceneNo();
			isLoadEnd_ = false;
			loadNextScene = std::thread(std::bind(&GameManager::LoadNextScene,this));
		}
		if (nextSceneNo_ != currentSceneNo_) {
			if (isLoadEnd_) {
				loadNextScene.detach();
				currentSceneNo_ = nextSceneNo_;
			}
		}


		sceneTable[currentSceneNo_]->Update();
		sceneTable[currentSceneNo_]->Draw();
	
		if (isLoad_) {
			Novice::ScreenPrintf(640,300,"NowLoading...");
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}
	if (isLoad_) {
		loadNextScene.join();
	}
	return 0;
}

void GameManager::LoadNextScene() {
	isLoadEnd_ = false;
	isLoad_ = true;
	sceneTable[nextSceneNo_]->Initialize();
	//初期化処理の時間(擬似)
	Sleep(3000);
	isLoadEnd_ = true;
	isLoad_ = false;
}