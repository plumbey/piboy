#pragma once

#include <raylib-cpp.hpp>

typedef enum pbModes { STATS, ITEMS, DATA } pbModes;

class pbInterface {
    raylib::Font font;
    raylib::Color fontColor;
    static constexpr int fontSize = 128;
    static constexpr int curTimeStrSize = 25;
    char curTimeStr[curTimeStrSize];
    Vector2 fontPixelSize = {0, 0};
    Vector2 fontPos = {0, 0};
    pbModes pbMode = STATS;

   public:
    pbInterface();
    void renderClock() const;
    void updateClock();

    void update();
};

class pbPage {
   public:
    pbPage();
    void update();
    void render() const;
};

class pbMode {};
