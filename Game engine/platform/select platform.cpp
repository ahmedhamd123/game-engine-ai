#include <iostream>
#include "platform/platform_selector.h"

int main() {
    PlatformSelector platformSelector;

    int choice;
    std::cout << "Select Platform:\n";
    std::cout << "1. Mobile\n";
    std::cout << "2. Tablet\n";
    std::cout << "3. PC\n";
    std::cout << "4. Console\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        platformSelector.setPlatform(PlatformType::Mobile);
        break;
    case 2:
        platformSelector.setPlatform(PlatformType::Tablet);
        break;
    case 3:
        platformSelector.setPlatform(PlatformType::PC);
        break;
    case 4:
        platformSelector.setPlatform(PlatformType::Console);
        break;
    default:
        std::cout << "Invalid choice, defaulting to PC." << std::endl;
        platformSelector.setPlatform(PlatformType::PC);
        break;
    }

    std::cout << "Platform configured successfully." << std::endl;
    return 0;
}
