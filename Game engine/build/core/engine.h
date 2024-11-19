#pragma once

#include <iostream>
#include <memory>

// Forward declarations for subsystems
class Renderer;
class InputManager;
class PluginManager;

class Engine {
public:
    Engine();  // Constructor
    ~Engine(); // Destructor

    bool initialize(); // Initialize all subsystems
    void handleInput(); // Process user inputs
    void update();      // Update game logic
    void render();      // Render the frame
    void shutdown();    // Clean up resources

    bool isRunning() const; // Check if the game loop is active

private:
    bool running; // Flag to control the game loop

    // Subsystems as smart pointers for memory management
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<InputManager> inputManager;
    std::unique_ptr<PluginManager> pluginManager;
};
