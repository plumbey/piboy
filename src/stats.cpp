#include "stats.hpp"

#include <ctime>
#include <string>

#include "Keyboard.hpp"
#include "raylib.h"
extern const int dbgScalingFactor;

using namespace pb;
void drawSelection(const raylib::Rectangle& rec) {
    const raylib::Color selection = {0, 95, 0, 255};
    const raylib::Color outline = {0, 238, 0, 255};
    raylib::Rectangle scaled = {
        rec.x * dbgScalingFactor, rec.y * dbgScalingFactor,
        rec.width * dbgScalingFactor, rec.height * dbgScalingFactor};

    DrawRectangleRec(scaled, selection);
    DrawRectangleLinesEx(scaled, 1 * dbgScalingFactor, outline);
}

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

Condition::Condition() {
    leftArmHealth = 0.2;
    rightArmHealth = 0.5;
    leftLegHealth = 0.9;
    rightLegHealth = 1.0;
    torsoHealth = 0.1;
    headHealth = 0.3;
}

void Condition::render(PageData& pd) {
    for (int i = 0; i < healthSize; i++) {
        Vector2 fontPos = {
            50, static_cast<float>((30 + i * 50)) * dbgScalingFactor};
        raylib::DrawTextEx(*pd.font,
                           healthNames[i] + std::to_string(healths[i]), fontPos,
                           15 * dbgScalingFactor, 0, pd.fontColor);
    }
}

Status::Status() {
    pages.push_back(&clk);
    pages.push_back(&cnd);
    pages.push_back(&rad);
    pages.push_back(&eff);
}

void Status::update(PageData& pd) {
    if (raylib::Keyboard::IsKeyPressed(KeyboardKey::KEY_J)) {
        curPage = (curPage + 1) % pages.size();
    } else if (raylib::Keyboard::IsKeyPressed(KeyboardKey::KEY_K)) {
        curPage = (curPage - 1) < 0 ? pages.size() - 1 : curPage - 1;
    }
    pages[curPage]->update(pd);
}

void Status::render(PageData& pd) { pages[curPage]->render(pd); }

StatsMode::StatsMode() {
    bg_template = raylib::Texture2D("resources/pb_stats.png");

    statusRec = raylib::Rectangle((33.5), (303), (44), (14));
    specialRec = raylib::Rectangle((116), (303), (87), (14));
    skillsRec = raylib::Rectangle((236), (303), (44), (14));
    perksRec = raylib::Rectangle((318), (303), (39), (14));
    generalRec = raylib::Rectangle((398), (303), (48), (14));

    // pages.push_back(&c);
    pages.push_back(&statusPage);
    pages.push_back(&specialPage);
    pages.push_back(&skillsPage);
    pages.push_back(&perksPage);
    pages.push_back(&generalPage);
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
    pages[curPage]->render(pd);
    drawSelection(selections[curPage]);

    bg_template.Draw();
}
