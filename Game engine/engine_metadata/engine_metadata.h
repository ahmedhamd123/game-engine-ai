#pragma once
#include <string>

class EngineMetadata {
public:
    static const std::string engineName;
    static const std::string engineVersion;

    // Function to get metadata
    static std::string getEngineInfo();
};
