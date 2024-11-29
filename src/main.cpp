#include "App.hpp"
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <raylib.h>
#include <format>

int main() {
	constexpr int windowWidth = 1024;
	constexpr int windowHeight = 640;

	InitWindow(windowWidth, windowHeight, "cube simulator 3d 2: it's cubin' time");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	SetExitKey(KEY_NULL);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 50);
	InitAudioDevice();

	App& app = App::getInstance();
	app.setState<MainMenu>();
	while (!WindowShouldClose()) {
		app.handleInput();
		app.update();
		app.draw();
	}
	CloseWindow();
	CloseAudioDevice();
}