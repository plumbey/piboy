#include "stats.hpp"

#include <ctime>

using namespace pb;

void Clock::render(PageData& pd) {
    raylib::DrawTextEx(*pd.font, curTimeStr, fontPos, fontSize, 0, fontColor);
}

void Clock::update(PageData& pd) {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    std::strftime(curTimeStr, curTimeStrSize, "%r", localTime);
    Vector2 fontPixelSize = pd.font->MeasureText(curTimeStr, fontSize, 0);
    fontPos = {static_cast<float>(pd.screenWidth) / 2 - fontPixelSize.x / 2,
               static_cast<float>(pd.screenHeight) / 2 - fontPixelSize.y / 2};
}

StatsMode::StatsMode() { pages.push_back(&c); }
void StatsMode::render(PageData& pd) {
    raylib::DrawText("In stats mode", 480, 320, 60, raylib::Color::White());
    pages[0]->render(pd);
}
void StatsMode::update(PageData& pd) { pages[0]->update(pd); }
