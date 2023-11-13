#pragma once
#include <stdint.h>
class InputManager
{
public:
	static InputManager* GetInstance();
	void Update();
	static bool PressKey(uint8_t);
	static bool TriggerKey(uint8_t);
	static bool ReleseKey(uint8_t);

private:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager operator=(const InputManager&) = delete;

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

};

