#pragma once

#include <raylib-cpp.hpp>

namespace pb {
typedef enum Modes { STATS, ITEMS, DATA } Modes;

class Page {
   public:
    // Page();
    //~Page();
    virtual void update();
    virtual void render();
};

class Mode {
   private:
    std::vector<Page> pages;

   public:
    // Mode();
    //~Mode();
    virtual void loadPage();
    virtual void unloadPage();
};

class Interface {
   private:
    Modes mode;
    const int piWidth = 480;
    const int piHeight = 320;
    const int dbgScalingFactor = 2;

    const int screenWidth = piWidth * dbgScalingFactor;
    const int screenHeight = piHeight * dbgScalingFactor;

    const raylib::Color bg = {0, 12, 0};
    raylib::Window w;
    void renderMode();
    Page* curPage;

   public:
    Interface();
    void loadMode();
    void update();
    void gameLoop();
};

}  // namespace pb
