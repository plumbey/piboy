#include "items.hpp"

void pb::ItemsMode::render(PageData& pd) {
    raylib::DrawText("In items mode", 480, 320, 60, raylib::Color::White());
}
