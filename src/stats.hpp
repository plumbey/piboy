#include <raylib-cpp.hpp>

#include "interface.hpp"

extern const int dbgScalingFactor;

namespace pb {
class Clock : public Page {
   private:
    const int fontSize = 64 * dbgScalingFactor;
    static constexpr int curTimeStrSize = 25;
    char curTimeStr[curTimeStrSize];
    Vector2 fontPixelSize = {0, 0};
    Vector2 fontPos = {0, 0};

   public:
    void update(PageData& pd) override;
    void render(PageData& pd) override;
};

class Condition : public Page {
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
    Condition();
    void update(PageData& pd) override {};
    void render(PageData& pd) override;
};

class Radiation : public Page {
   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override {};
};

class Effects : public Page {
   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override {};
};
class Engineering : public Page {
   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override {};
};

class Status : public Page {
   private:
    static constexpr int selectionAmt = 5;
    union {
        struct {
            raylib::Rectangle cndRec;
            raylib::Rectangle radRec;
            raylib::Rectangle effRec;
            raylib::Rectangle clkRec;
            raylib::Rectangle engRec;
        };
        raylib::Rectangle selections[selectionAmt];
    };
    Clock clk;
    Condition cnd;
    Radiation rad;
    Effects eff;
    Engineering eng;
    int curPage = 0;
    std::vector<Page*> pages;

   public:
    void update(PageData& pd) override;
    void render(PageData& pd) override;
    Status();
};

class Special : public Page {
   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override {};
};
class Skills : public Page {
   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override {};
};
class Perks : public Page {
   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override {};
};
class General : public Page {
   public:
    void update(PageData& pd) override {};
    void render(PageData& pd) override {};
};

class StatsMode : public Mode {
   private:
    static constexpr int selectionAmt = 5;
    union {
        struct {
            raylib::Rectangle statusRec;
            raylib::Rectangle specialRec;
            raylib::Rectangle skillsRec;
            raylib::Rectangle perksRec;
            raylib::Rectangle generalRec;
        };
        raylib::Rectangle selections[selectionAmt];
    };

    raylib::Texture2D bg_template;
    Status statusPage;
    Special specialPage;
    Skills skillsPage;
    Perks perksPage;
    General generalPage;

   public:
    void update(PageData& pd) override;
    void render(PageData& pd) override;
    StatsMode();
};

}  // namespace pb
