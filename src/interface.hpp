#pragma once

#include <raylib-cpp.hpp>
#include <vector>

namespace pb {
struct PageData {
    raylib::Font* font;
    const raylib::Color fontColor = {0, 238, 0};
    int screenWidth;
    int screenHeight;
};

class Page {
   public:
    virtual void update(PageData& pd) = 0;
    virtual void render(PageData& pd) = 0;
    virtual ~Page() = default;
    Page() = default;
};

class Mode {
   protected:
    int curPage;
    std::vector<Page*> pages;
    // virtual void loadPage() = 0;
    // virtual void unloadPage() = 0;

   public:
    virtual void render(PageData& pd) = 0;
    virtual void update(PageData& pd) = 0;
    virtual ~Mode() = default;
    Mode() = default;
};
}  // namespace pb
