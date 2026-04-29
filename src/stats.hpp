#include <raylib-cpp.hpp>

#include "interface.hpp"

namespace pb {
class Clock : public Page {
    raylib::Color fontColor = {0, 238, 0};
    static constexpr int fontSize = 256;
    static constexpr int curTimeStrSize = 25;
    char curTimeStr[curTimeStrSize];
    Vector2 fontPixelSize = {0, 0};
    Vector2 fontPos = {0, 0};

   public:
    void update(PageData& pd);
    void render(PageData& pd);
};

class StatsMode : public Mode {
   private:
    Clock c;

   public:
    void update(PageData& pd);
    void render(PageData& pd);
    StatsMode();
};

}  // namespace pb
