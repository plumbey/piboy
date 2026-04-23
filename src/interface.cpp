#include "interface.hpp"

typedef struct State {
    typedef enum Modes { STATS, ITEMS, DATA } Modes;
    Modes mode;
    // Returns true if the mode has switched from the previous one
    bool update() {
        Modes prev = mode;
        if (raylib::Keyboard::IsKeyDown(KEY_S)) {
            mode = STATS;
        } else if (raylib::Keyboard::IsKeyDown(KEY_I)) {
            mode = ITEMS;
        } else if (raylib::Keyboard::IsKeyDown(KEY_D)) {
            mode = DATA;
        }

        return prev != mode;
    }

    void render(raylib::Font& f) {
        if (mode == Modes::STATS) {
            // raylib::DrawTextEx(f, "In Stats!", raylib::Vector2{480, 320}, 60,
            // 0,
            //                    raylib::Color{0, 255, 0});

        } else if (mode == Modes::ITEMS) {
            // raylib::DrawTextEx(f, "In Items!", raylib::Vector2{480, 320}, 60,
            // 0,
            //                    raylib::Color{0, 255, 0});
        } else if (mode == Modes::DATA) {
            // raylib::DrawTextEx(f, "In Data!", raylib::Vector2{480, 320}, 60,
            // 0,
            //                    raylib::Color{0, 255, 0});
        }
    }
} curMode;
