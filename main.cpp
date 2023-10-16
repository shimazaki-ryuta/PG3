#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

class Enemy
{
public:
	enum class Phase
	{
		Approach,
		Shot,
		Leave,
	};
	void Update() {
		(this->*phaseTable[static_cast<size_t>(phase_)])();
	};
	void Approach() {
		printf("近接\n");
		phase_ = Phase::Shot;
	};
	void Shot() {
		printf("射撃\n");
		phase_ = Phase::Leave;
	};
	void Leave() {
		printf("離脱\n");
		//phase_ = Phase::Approach;
	};

private:
	Phase phase_ = Phase::Approach;
	static void(Enemy::* phaseTable[])();
};

void(Enemy::* Enemy::phaseTable[])() = {
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::Leave
};

int main() {
	Enemy enemy;
	while (1)
	{
		enemy.Update();

		Sleep(1000);
	}
	return 0;
}