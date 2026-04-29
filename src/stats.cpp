#include "stats.hpp"

#include <ctime>
#include <string>

#include "Keyboard.hpp"

using namespace pb;

void Clock::render(PageData& pd) {
    raylib::DrawTextEx(*pd.font, curTimeStr, fontPos, fontSize, 0,
                       pd.fontColor);
}

void Clock::update(PageData& pd) {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    std::strftime(curTimeStr, curTimeStrSize, "%r", localTime);
    Vector2 fontPixelSize = pd.font->MeasureText(curTimeStr, fontSize, 0);
    fontPos = {((pd.screenWidth) - fontPixelSize.x) / 2,
               ((pd.screenHeight) - fontPixelSize.y) / 2};
}

Status::Status() {
    leftArmHealth = 0.2;
    rightArmHealth = 0.5;
    leftLegHealth = 0.9;
    rightLegHealth = 1.0;
    torsoHealth = 0.1;
    headHealth = 0.3;
}

void Status::render(PageData& pd) {
    for (int i = 0; i < healthSize; i++) {
        Vector2 fontPos = {480, static_cast<float>(320 + i * 100)};
        raylib::DrawTextEx(*pd.font,
                           healthNames[i] + std::to_string(healths[i]), fontPos,
                           60, 0, pd.fontColor);
    }
}

StatsMode::StatsMode() {
    pages.push_back(&c);
    pages.push_back(&s);
}

void StatsMode::update(PageData& pd) {
    if (raylib::Keyboard::IsKeyPressed(KeyboardKey::KEY_PERIOD)) {
        curPage = (curPage + 1) % pages.size();
    } else if (raylib::Keyboard::IsKeyPressed(KeyboardKey::KEY_COMMA)) {
        curPage = (curPage - 1) < 0 ? pages.size() - 1 : curPage - 1;
    }

    pages[curPage]->update(pd);
}

void StatsMode::render(PageData& pd) {
    // raylib::DrawText("In stats mode", 700, 320, 60, raylib::Color::White());
    pages[curPage]->render(pd);
}
