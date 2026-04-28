#include "interface.hpp"

#include <iostream>

using namespace pb;

State::State(raylib::Font* f) {
    s.font = f;
    std::cout << "Created State" << std::endl;
}

State::~State() {}

// Returns true if the curMode has switched from the previous one
bool State::update() {
    Mode_e prevMode = curMode;
    if (raylib::Keyboard::IsKeyDown(KEY_S)) {
        curMode = STATS;
        s.update();
    } else if (raylib::Keyboard::IsKeyDown(KEY_I)) {
        curMode = ITEMS;
    } else if (raylib::Keyboard::IsKeyDown(KEY_D)) {
        curMode = DATA;
    }

    return prevMode != curMode;
}

void State::render() {
    switch (curMode) {
        case STATS: {
            s.render();
            break;
        }
        case ITEMS:
            exit(1);
        case DATA:
            exit(1);
    }
}
