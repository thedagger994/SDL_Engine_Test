// Core Libraries
#include <crtdbg.h>
#include <iostream>
#include <Windows.h>

#include "Game.h"

constexpr float FPS = 60.0f;	// Target FPS
constexpr float DELAY_TIME = 1000.0f / FPS;	// Target time between frames

/**
 * \brief Program Entry Point
 */
int main(int argc, char* args[])
{
	Uint32 frames = 0;

	// show and position the application console
	AllocConsole();
	auto console = freopen("CON", "w", stdout);
	const auto window_handle = GetConsoleWindow();
	MoveWindow(window_handle, 100, 700, 800, 200, TRUE);

	// Display Main SDL Window
	Game::Instance().Init("SDL_Engine v0.29", 100, 100, 800, 600, false);

	// Main Game Loop
	while (Game::Instance().IsRunning())
	{
		//get time in ms at the start of the frame
		const auto frame_start = static_cast<float>(SDL_GetTicks());

		//Calling three functions in sequence (functions are a list of instructions)
		Game::Instance().HandleEvents();		// Read inputs from the player
		Game::Instance().Update();				// Update the game state according to the input
		Game::Instance().Render();				// Draw to the screen

		// Get time that has passed this frame
		if (const float frame_time = static_cast<float>(SDL_GetTicks()) - frame_start;
			frame_time < DELAY_TIME) // If it took less than 60 ms then it will delay
		{
			SDL_Delay(static_cast<int>(DELAY_TIME - frame_time));
		}

		// delta time. How much time time has passed since the start  of the frame
		const auto delta_time = (static_cast<float>(SDL_GetTicks()) - frame_start) / 1000.0f;
		
		//Setting a variable in-game?
		Game::Instance().SetDeltaTime(delta_time);

		frames++;
		Game::Instance().SetFrames(frames);

	}

	Game::Instance().Clean();
	return 0;
}

