#pragma once

class Mode {
   protected:
    // virtual void loadPage();
    // virtual void unloadPage();

   public:
    virtual void render() = 0;
};
