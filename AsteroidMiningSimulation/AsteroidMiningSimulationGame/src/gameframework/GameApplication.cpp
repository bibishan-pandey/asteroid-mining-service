#include "gameframework/GameApplication.h"

mining_simulation::Application* GetApplication() {
    return new mining_simulation::GameApplication();
}

namespace mining_simulation {
    GameApplication::GameApplication() {

    }
}
