#pragma once

#include <raylib-cpp.hpp>
#include <vector>

namespace pb {
typedef struct {
    raylib::Font* font;
    int screenWidth;
    int screenHeight;
} PageData;

class Page {
   public:
    Page() = default;
    virtual ~Page() = default;
    virtual void update(PageData& pd) = 0;
    virtual void render(PageData& pd) = 0;
};

class Mode {
   protected:
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
