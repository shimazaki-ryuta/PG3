#pragma once
#include <memory>
#include <vector>
#include "IScene.h"
#include "TitleScene.h"
#include <thread>
class GameManager
{
public:
	GameManager();
	~GameManager();
	int Run();
	void LoadNextScene();
private:
	//std::unique_ptr<IScene> scene;
	//std::unique_ptr<IScene> nextScene;
	int currentSceneNo_;
	int nextSceneNo_;

	std::unique_ptr<IScene> sceneTable[3];
	std::thread loadNextScene;
	bool isLoadEnd_ = false;
	bool isLoad_ = false;
};

