#pragma once
#include <string>

class SplashScreen {
public:
    static void show(const std::string &message, int duration = 3000);
};