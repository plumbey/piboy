#include "modes.hpp"

namespace pb {
class DataMode : public Mode {
   public:
    DataMode();
    ~DataMode();
    void render() {};
    void update() {};
};
}  // namespace pb
