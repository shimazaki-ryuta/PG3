#include "InputManager.h"
#include <string.h>
#include "Novice.h"
InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

}

bool InputManager::PressKey(uint8_t keyCode) {
	return GetInstance()->keys[keyCode];
}

bool InputManager::TriggerKey(uint8_t keyCode) {
	return !GetInstance()->preKeys[keyCode] && GetInstance()->keys[keyCode];
}

bool InputManager::ReleseKey(uint8_t keyCode) {
	return GetInstance()->preKeys[keyCode] && !GetInstance()->keys[keyCode];
}
