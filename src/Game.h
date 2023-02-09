#pragma once
#ifndef __GAME__
#define __GAME__

// Core Libraries
#include <iostream>
#include <string>
#include <vector>
#include "SceneState.h"

#include <SDL.h>

// Game Managers
#include "CollisionManager.h"

// Scenes
#include "StartScene.h"
#include "PlayScene.h"
#include "EndScene.h"

#include "Config.h"

#include "ImGuiWindowFrame.h"

class Game
{
public:
	//This class Game is set up such that you don't have to make variables of type game. There is one declared here.
	//You can access the singular Game variable by calling this function Instance(), which is a member of the Game class.
	//The static keyword makes this function accessible with just the class name, not the actual variable of type Game.
	//We can call this function as if Game was a namespace i.e. Game::Instance()
	static Game& Instance()
	{
		static Game instance;
		return instance;
	}
	
	//Functions are reusable lists of instructions. Functions declared inside a class are Member Functions
	//These Member Functions are specifically called on a variable of type Game, using the "." access operator
	// + and - are opperators like the . (period operator)
	//In math, f(x) = 2x is a function which takes x and returns 2 * x, which we can assume is graphable on xand y axis
	//A function in C++ takes inputs, also called parameters or arguments, and gives one output.
	//

	// simply set the isRunning variable to true
	void Init();
	bool Init(const char* title, int x, int y, int width, int height, bool fullscreen);

	// public life cycle functions
	void Render() const;
	void Update() const;
	void HandleEvents() const;
	void Clean() const;
	void Start();
	void Quit();

	// getter and setter functions
	[[nodiscard]] glm::vec2 GetMousePosition() const;

	void SetFrames(Uint32 frames);
	[[nodiscard]] Uint32 GetFrames() const;

	[[nodiscard]] float GetDeltaTime() const;
	void SetDeltaTime(float time);

	[[nodiscard]] bool IsRunning() const;
	void ChangeSceneState(SceneState new_state);

	[[nodiscard]] SDL_Window* GetWindow() const;

private:
	Game();
	~Game();

	// game properties
	bool m_bRunning;
	Uint32 m_frames;
	float m_deltaTime{};
	glm::vec2 m_mousePosition;

	// scene variables
	Scene* m_pCurrentScene;
	SceneState m_currentSceneState;

	// storage structures
	std::shared_ptr<SDL_Window> m_pWindow;
};


#endif /* defined (__GAME__) */

