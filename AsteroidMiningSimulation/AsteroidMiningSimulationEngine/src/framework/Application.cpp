#include <iostream>
#include <framework/Application.h>

namespace mining_simulation {
    Application::Application(): m_targetFrameRate(60.f), m_tickClock{} {
        // Target resolution
        const sf::Vector2u baseResolution(1024, 1440);

        // Get actual screen resolution
        const sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
        const unsigned int screenHeight = desktopMode.height;
        const unsigned int screenWidth = desktopMode.width;

        // Scale width based on the available screen height (accounting for taskbar)
        const float scaleFactor = static_cast<float>(screenHeight) / baseResolution.y;
        const unsigned int windowWidth = static_cast<unsigned int>(baseResolution.x * scaleFactor);
        const unsigned int windowHeight = static_cast<unsigned int>(baseResolution.y * scaleFactor);

        // Create the window with decorations (title bar included)
        m_window.create(sf::VideoMode(windowWidth, windowHeight), "Asteroid Mining Simulation", sf::Style::None);

        // After the window is created, get the size, and adjust for the title bar (or decoration height)
        const sf::Vector2u actualSize = m_window.getSize();
        const unsigned int titleBarHeight = actualSize.y - windowHeight;
        const unsigned int adjustedHeight = windowHeight - titleBarHeight;

        // Set the new window size, adjusted for the title bar
        m_window.setSize(sf::Vector2u(windowWidth, adjustedHeight));

        const int posX = (screenWidth - windowWidth) / 2; // Center horizontally
        constexpr int posY = 0; // Position at the top

        // Set window position
        m_window.setPosition(sf::Vector2i(posX, posY));
    }

    void Application::Run() {
        m_tickClock.restart();

        float accumulatedTime = 0.f;
        const float targetDeltaTime = 1.f / m_targetFrameRate;

        while (m_window.isOpen()) {
            sf::Event event;
            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed
                    || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                ) {
                    m_window.close(); // Close window on Escape key press
                }
            }

            const float frameDeltaTime = m_tickClock.restart().asSeconds();
            accumulatedTime += frameDeltaTime;

            while (accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    }

    void Application::RenderInternal() {
        m_window.clear();

        // Renders our objects here
        Render();

        m_window.display();
    }

    void Application::Render() {
        sf::RectangleShape rect{sf::Vector2f{100, 100}};
        rect.setFillColor(sf::Color::White);
        rect.setOrigin(50.f, 50.f);
        rect.setPosition(m_window.getSize().x / 2, m_window.getSize().y / 2);
        m_window.draw(rect);
    }

    void Application::TickInternal(float deltaTime) {
        Tick(deltaTime);
    }

    void Application::Tick(float deltaTime) {
    }
}
