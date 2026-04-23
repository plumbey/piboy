#include "interface.hpp"
#include "raylib.h"

int main() {
    // Initialization
    const int piWidth = 480;
    const int piHeight = 320;
    const int dbgScalingFactor = 2;

    const int screenWidth = piWidth * dbgScalingFactor;
    const int screenHeight = piHeight * dbgScalingFactor;

    raylib::Color bg = raylib::Color{0, 12, 0};
    raylib::Window w(screenWidth, screenHeight, "PiBoy!");
    w.SetConfigFlags(FLAG_WINDOW_UNDECORATED);

    SetTargetFPS(60);

    pbInterface piboy;
    while (!w.ShouldClose())  // Detect window close button or ESC key
    {
        // Update
        piboy.updateClock();
        // Draw
        BeginDrawing();
        w.ClearBackground(bg);
        piboy.renderClock();
        EndDrawing();
    }

    return 0;
}
