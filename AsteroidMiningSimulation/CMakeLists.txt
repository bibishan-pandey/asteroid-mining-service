cmake_minimum_required(VERSION 3.27.7)
project(
        AsteroidMiningSimulation
        VERSION 1.0.0
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(ASTEROID_MINING_SIMULATION_ENGINE_TARGET_NAME AsteroidMiningSimulationEngine)
set(ASTEROID_MINING_SIMULATION_GAME_TARGET_NAME AsteroidMiningSimulationGame)

add_subdirectory(AsteroidMiningSimulationEngine)
add_subdirectory(AsteroidMiningSimulationGame)
