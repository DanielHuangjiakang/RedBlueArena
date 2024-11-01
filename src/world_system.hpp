#pragma once

// internal
#include "common.hpp"

// stlib
#include <vector>
#include <random>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_mixer.h>

#include "render_system.hpp"

// Container for all our entities and game logic. Individual rendering / update is
// deferred to the relative update() methods
class WorldSystem
{
public:
	WorldSystem();

	// Creates a window
	GLFWwindow* create_window();

	// starts the game
	void init(RenderSystem* renderer);

	// Releases all associated resources
	~WorldSystem();

	// Steps the game ahead by ms milliseconds
	bool step(float elapsed_ms);

	// Check for collisions
	void handle_collisions();

	// Should the game be over ?
	bool is_over()const;
private:
	// Input callback functions
	void on_key(int key, int, int action, int mod);
	void on_mouse_move(vec2 pos);

	// restart level
	void restart_game();

	// OpenGL window handle
	GLFWwindow* window;

	// Game state
	RenderSystem* renderer;
	float current_speed;
	Entity player1;
	Entity player2;
	bool player1_right_button = false;
	bool player1_left_button = false;
	bool player2_right_button = false;
	bool player2_left_button = false;

	// Stage atrributes
	Entity ground;
	Entity platform1;
	Entity platform2;
	Entity platform3;

	// music references
	Mix_Music* background_music;

	Mix_Chunk* end_music;
	Mix_Chunk* hit_sound;
	Mix_Chunk* shoot_sound;

	Mix_Chunk* salmon_dead_sound;
	Mix_Chunk* salmon_eat_sound;

	// C++ random number generator
	std::default_random_engine rng;
	std::uniform_real_distribution<float> uniform_dist; // number between 0..1
};
