#include "platform_selector.h"
#include <iostream>

PlatformSelector::PlatformSelector() : currentPlatform(PlatformType::PC) {
    // Default to PC
}

PlatformSelector::~PlatformSelector() {}

void PlatformSelector::setPlatform(PlatformType platform) {
    currentPlatform = platform;
    configurePlatform();
}

PlatformType PlatformSelector::getPlatform() const {
    return currentPlatform;
}

void PlatformSelector::configurePlatform() {
    switch (currentPlatform) {
    case PlatformType::Mobile:
        std::cout << "Configuring for Mobile..." << std::endl;
        // Adjust settings specific to mobile
        break;
    case PlatformType::Tablet:
        std::cout << "Configuring for Tablet..." << std::endl;
        // Adjust settings specific to tablets
        break;
    case PlatformType::PC:
        std::cout << "Configuring for PC..." << std::endl;
        // Adjust settings specific to PC
        break;
    case PlatformType::Console:
        std::cout << "Configuring for Console..." << std::endl;
        // Adjust settings specific to consoles
        break;
    }
}
