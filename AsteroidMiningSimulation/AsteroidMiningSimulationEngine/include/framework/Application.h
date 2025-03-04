#pragma once
#include <SFML/Graphics.hpp>

namespace mining_simulation {
    class Application {
    public:
        virtual ~Application() = default;

        Application();

        void Run();

    private:
        // Template function for reserving the parts of code we need to abstract out our calling sequence
        void TickInternal(float deltaTime);

        void RenderInternal();

        // Override by top classes
        virtual void Render();

        virtual void Tick(float deltaTime);

        sf::RenderWindow m_window;
        float m_targetFrameRate;
        sf::Clock m_tickClock;
    };
}
