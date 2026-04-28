#include "stats.hpp"

#include <ctime>

using namespace pb;

Clock::Clock(raylib::Font* f) {
    // Use large font size (400) to avoid pixelation
    font = f;
    fontColor = raylib::Color{0, 238, 0};
}

void Clock::render() {
    raylib::DrawText("hi", 480, 320, 60, RAYWHITE);
    // raylib::DrawTextEx(*font, curTimeStr, fontPos, fontSize, 0, fontColor);
}

void Clock::update() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    std::strftime(curTimeStr, curTimeStrSize, "%r", localTime);
    Vector2 fontPixelSize = font->MeasureText(curTimeStr, fontSize, 0);
    fontPos = {480 - fontPixelSize.x / 2, 320 - fontPixelSize.y / 2};
}

StatsMode::StatsMode(raylib::Font* f) { c = new Clock(f); }
StatsMode::~StatsMode() {}

void StatsMode::render() { c->render(); }
void StatsMode::update() { c->update(); }
