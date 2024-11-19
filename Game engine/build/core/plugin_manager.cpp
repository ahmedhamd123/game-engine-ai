#pragma once

#include <string>
#include <vector>
#include <iostream>

class PluginManager {
public:
    void loadPlugins(const std::string& directory);
    void unloadPlugins();
};
