#include "data.hpp"
#include "items.hpp"
#include "stats.hpp"

const int piWidth = 480;
const int piHeight = 320;
const int dbgScalingFactor = 4;

const int screenWidth = piWidth * dbgScalingFactor;
const int screenHeight = piHeight * dbgScalingFactor;
const raylib::Color bg = {0, 12, 0};

int main() {
    raylib::Window w(screenWidth, screenHeight, "piboy!",
                     FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(60);
    raylib::Font f =
        LoadFontEx("resources/monofonto.otf", 200 * dbgScalingFactor, NULL, 0);
    pb::PageData pd = {&f, screenWidth, screenHeight};
    pb::StatsMode stats;
    pb::DataMode data;
    pb::ItemsMode items;
    pb::Mode* curMode = &stats;

    while (!w.ShouldClose()) {
        switch (GetKeyPressed()) {
            case KeyboardKey::KEY_S:
                curMode = &stats;
                break;
            case KeyboardKey::KEY_D:
                curMode = &data;
                break;
            case KeyboardKey::KEY_I:
                curMode = &items;
                break;
        }

        curMode->update(pd);

        BeginDrawing();
        w.ClearBackground(bg);
        curMode->render(pd);
        EndDrawing();
    }

    return 0;
}
