#pragma once

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum MOUSE_BUTTONS
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler * getInstance();
	void update();
	void clean();

	bool isKeyDown(SDL_Scancode key);

	bool getMouseButtonState(int buttonNumber);

	Vector2D * getMousePosition();

private:
	InputHandler();
	~InputHandler() {}

	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);

	static InputHandler * _instance;

	const Uint8 * _keyStates;

	std::vector<bool> _mouseButtonStates;

	Vector2D * _mousePosition;
};
