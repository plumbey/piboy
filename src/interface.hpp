#pragma once

#include <raylib-cpp.hpp>

namespace pb {

class Page {
   public:
    Page();
    ~Page();
    virtual void update() {};
    virtual void render() {};
};

class Mode {
   private:
    std::vector<Page> pages;

   public:
    Mode();
    virtual ~Mode();
    virtual void loadPage();
    virtual void unloadPage();
};
}  // namespace pb
