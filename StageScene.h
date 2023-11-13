#pragma once
#include "IScene.h"
#include "matrix.h"
#include "Player.h"
#include "Enemy.h"
#include <memory>
class StageScene :
    public IScene
{
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
private:
    Matrix3x3 vpVp_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Enemy> enemy_;
};

