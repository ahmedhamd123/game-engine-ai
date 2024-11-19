#include "device_info.h"
#include <iostream>

bool DeviceInfo::checkHardwareCapabilities() {
    std::cout << "Checking hardware capabilities...\n";
    // Simulate device capability check
    int ram = 8; // Simulate available RAM in GB
    if (ram < 4) {
        std::cerr << "Insufficient RAM. Minimum 4GB required.\n";
        return false;
    }
    return true;
}
