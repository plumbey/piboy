#include "data.hpp"

using namespace pb;

void DataMode::render(PageData& pd) {
    raylib::DrawText("In data mode", 480, 320, 60, raylib::Color::White());
}
