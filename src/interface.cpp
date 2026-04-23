#include "interface.hpp"

#include <iostream>
#include <raylib-cpp.hpp>

#include "Keyboard.hpp"

pbInterface::pbInterface() {
    // Use large font size (400) to avoid pixelation
    font = raylib::LoadFontEx("resources/monofonto rg.otf", 400, NULL, 0);
    fontColor = raylib::Color{0, 238, 0};
}

void pbInterface::renderClock() const {
    raylib::DrawTextEx(font, curTimeStr, fontPos, fontSize, 0, fontColor);
}

void pbInterface::updateClock() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    std::strftime(curTimeStr, curTimeStrSize, "%H:%M", localTime);
    Vector2 fontPixelSize = font.MeasureText(curTimeStr, fontSize, 0);
    fontPos = {480 - fontPixelSize.x / 2, 320 - fontPixelSize.y / 2};
    std::cout << fontPos.x << " " << fontPos.y << std::endl;
}

void pbInterface::update() {
    if (raylib::Keyboard::IsKeyPressed('S')) {
        pbMode = STATS;

    } else if (raylib::Keyboard::IsKeyPressed('I')) {
        pbMode = ITEMS;
    } else if (raylib::Keyboard::IsKeyPressed('D')) {
        pbMode = DATA;
    }
}

/*
void pbInterface::changeMode(pbModes mode) {
}
*/
