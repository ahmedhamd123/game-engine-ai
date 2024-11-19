#include "engine.h"
#include "core/engine_metadata.h"
#include <iostream>
#include "core/branding_config.h"
#include "core/branding_config.h
#include "core/branding_config.h
#include "platform/platform_selector.h"

int main() {
    PlatformSelector platformSelector;

    // Example: Set platform to Mobile
    platformSelector.setPlatform(PlatformType::Mobile);

    // Retrieve and print the selected platform
    PlatformType selectedPlatform = platformSelector.getPlatform();
    std::cout << "Current Platform: " 
              << (selectedPlatform == PlatformType::Mobile ? "Mobile" : 
                  selectedPlatform == PlatformType::Tablet ? "Tablet" : 
                  selectedPlatform == PlatformType::PC ? "PC" : "Console")
              << std::endl;

    return 0;
}
if (BrandingConfig::enableBranding) {
    SplashScreen::show(EngineMetadata::getEngineInfo(), 3000);
}

int main() {
    std::cout << EngineMetadata::getEngineInfo() << std::endl;
    return 0;
}

int main() {
    // Instantiate the core engine
    Engine engine;

    // Initialize the engine and check for errors
    if (!engine.initialize()) {
        std::cerr << "Engine initialization failed.\n";
        return -1; // Exit if initialization fails
    }

    // Main game loop
    while (engine.isRunning()) {
        engine.handleInput();  // Process user input
        engine.update();       // Update game logic
        engine.render();       // Render graphics
    }

    // Cleanly shut down the engine
    engine.shutdown();

    return 0;
}
