#include "interface.hpp"

namespace pb {
class ItemsMode : public Mode {
   private:
   public:
    void update(PageData& pd) {};
    void render(PageData& pd);
    ItemsMode() = default;
};
}  // namespace pb
