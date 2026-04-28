#include <raylib-cpp.hpp>

#include "modes.hpp"

namespace pb {
class Clock {
   private:
    raylib::Font* font;
    raylib::Color fontColor;
    static constexpr int fontSize = 128;
    static constexpr int curTimeStrSize = 25;
    char curTimeStr[curTimeStrSize];
    Vector2 fontPixelSize = {0, 0};
    Vector2 fontPos = {0, 0};

   public:
    Clock(raylib::Font* f);

    void render();
    void update();
};

class StatsMode : public Mode {
   private:
    Clock* c;

   public:
    raylib::Font* font;
    StatsMode() {};
    ~StatsMode();
    StatsMode(raylib::Font* f);
    void render();
    void update();
};

}  // namespace pb
