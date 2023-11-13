#include "TitleScene.h"
#include "Novice.h"
#include "InputManager.h"
void TitleScene::Initialize() {
	sceneNo = TITLE;
}
void TitleScene::Update() {
	if (InputManager::TriggerKey(DIK_SPACE)) {
		sceneNo=STAGE;
	}
}
void TitleScene::Draw() {
	Novice::ScreenPrintf(640, 360, "TITLESCENE");
	Novice::ScreenPrintf(640, 380, "NEXT:SPACE");

}