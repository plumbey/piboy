#include "interface.hpp"

namespace pb {
class DataMode : public Mode {
   private:
   public:
    void update(PageData& pd) {};
    void render(PageData& pd);
    DataMode() = default;
};
}  // namespace pb
