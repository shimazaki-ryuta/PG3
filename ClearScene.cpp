#include "ClearScene.h"
#include "Novice.h"
#include "InputManager.h"
void ClearScene::Initialize() {
	sceneNo = CLEAR;
}
void ClearScene::Update() {
	if (InputManager::TriggerKey(DIK_SPACE)) {
		sceneNo = TITLE;
	}
}
void ClearScene::Draw() {
	Novice::ScreenPrintf(640, 360, "CLEARSCENE");
	Novice::ScreenPrintf(640, 380, "NEXT:SPACE");

}