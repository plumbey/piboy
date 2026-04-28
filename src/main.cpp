// #include "StatsMode.hpp"
#include "interface.hpp"

const int piWidth = 480;
const int piHeight = 320;
const int dbgScalingFactor = 4;

const int screenWidth = piWidth * dbgScalingFactor;
const int screenHeight = piHeight * dbgScalingFactor;
const raylib::Color bg = {0, 12, 0};

int main() {
    raylib::Window w(screenWidth, screenHeight, "piboy!",
                     FLAG_WINDOW_UNDECORATED);
    raylib::Font f =
        LoadFontEx("resources/monofonto.otf", 200 * dbgScalingFactor, NULL, 0);
    pb::State state(&f);
    // Clock c(&f);
    SetTargetFPS(60);

    while (!w.ShouldClose()) {
        state.update();
        // c.update();

        BeginDrawing();
        state.render();
        w.ClearBackground(bg);
        // c.render();
        EndDrawing();
    }

    return 0;
}
