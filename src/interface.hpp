#pragma once

#include <raylib-cpp.hpp>

#include "data.hpp"
#include "items.hpp"
#include "stats.hpp"

namespace pb {

class State {
   private:
    typedef enum Mode_e { STATS, ITEMS, DATA } Mode_e;
    Mode_e curMode = STATS;
    StatsMode s;
    raylib::Font* font;

   public:
    State(raylib::Font* font);
    ~State();
    bool update();
    void render();
};
}  // namespace pb
