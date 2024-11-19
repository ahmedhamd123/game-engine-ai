#include "splash_screen.h"
#include <iostream>
#include <thread>
#include <chrono>

void SplashScreen::show(const std::string &message, int duration) {
    std::cout << "=== " << message << " ===" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
}
