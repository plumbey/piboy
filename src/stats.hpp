#include <raylib-cpp.hpp>

#include "interface.hpp"

namespace pb {
class Clock : public Page {
   private:
    static constexpr int fontSize = 256;
    static constexpr int curTimeStrSize = 25;
    char curTimeStr[curTimeStrSize];
    Vector2 fontPixelSize = {0, 0};
    Vector2 fontPos = {0, 0};

   public:
    void update(PageData& pd) override;
    void render(PageData& pd) override;
};

class Status : public Page {
   private:
    static constexpr int healthSize = 6;
    union {
        struct {
            float leftArmHealth;
            float rightArmHealth;
            float leftLegHealth;
            float rightLegHealth;
            float torsoHealth;
            float headHealth;
        };
        float healths[healthSize];
    };
    std::string healthNames[healthSize] = {
        "Left Arm Health: ",  "Right Arm Health: ", "Left Leg Health: ",
        "Right Leg Health: ", "Torso Health: ",     "Head Health: ",
    };

   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override;
    Status();
};

class StatsMode : public Mode {
   private:
    Clock c;
    Status s;

   public:
    void update(PageData& pd) override;
    void render(PageData& pd) override;
    StatsMode();
};

}  // namespace pb
