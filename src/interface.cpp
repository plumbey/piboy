#include "interface.hpp"

#include <raylib-cpp.hpp>

#include "StatsMode.hpp"
#include "raylib.h"

using namespace pb;

void Page::render() {};
void Page::update() {};

raylib::Font f;

Interface::Interface() {
    mode = STATS;
    w.Init(screenWidth, screenHeight);
    SetTargetFPS(60);
    f = LoadFontEx("resources/monofonto.otf", 400, NULL, 0);
    curPage = new Clock(&f);
}

void Interface::gameLoop() {
    raylib::Font font = LoadFontEx("resources/monofonto.otf", 400, NULL, 0);
    while (!w.ShouldClose())  // Detect window close button or ESC key
    {
        // Update
        curPage->update();
        // Draw
        BeginDrawing();
        w.ClearBackground(bg);
        curPage->render();
        EndDrawing();
    }
}

void Interface::update() {
    if (raylib::Keyboard::IsKeyPressed('S')) {
        mode = STATS;
    } else if (raylib::Keyboard::IsKeyPressed('I')) {
        mode = ITEMS;
    } else if (raylib::Keyboard::IsKeyPressed('D')) {
        mode = DATA;
    }
}

void Interface::renderMode() {}
