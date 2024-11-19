#include "engine.h"
#include "renderer.h"
#include "input_manager.h"
#include "plugin_manager.h"

Engine::Engine() : running(false) {}

Engine::~Engine() {}

bool Engine::initialize() {
    std::cout << "[Engine] Initializing subsystems...\n";

    // Initialize Renderer
    renderer = std::make_unique<Renderer>();
    if (!renderer->initialize()) {
        std::cerr << "[Error] Renderer initialization failed.\n";
        return false;
    }

    // Initialize Input Manager
    inputManager = std::make_unique<InputManager>();
    inputManager->initialize();

    // Initialize Plugin Manager
    pluginManager = std::make_unique<PluginManager>();
    pluginManager->loadPlugins("plugins/");

    // Mark the engine as running
    running = true;
    std::cout << "[Engine] Initialization complete.\n";

    return true;
}

void Engine::handleInput() {
    if (inputManager) {
        inputManager->pollInput();
    }
}

void Engine::update() {
    // Update logic for game state
    std::cout << "[Engine] Updating game logic...\n";
}

void Engine::render() {
    if (renderer) {
        renderer->draw();
    }
}

void Engine::shutdown() {
    std::cout << "[Engine] Shutting down subsystems...\n";

    // Shutdown subsystems
    if (pluginManager) {
        pluginManager->unloadPlugins();
    }

    if (renderer) {
        renderer->shutdown();
    }

    running = false;
}

bool Engine::isRunning() const {
    return running;
}
