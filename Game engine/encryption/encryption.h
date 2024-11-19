#pragma once
#include <string>

class Encryption {
public:
    static void encryptFile(const std::string& filePath, const std::string& key);
    static void decryptFile(const std::string& filePath, const std::string& key);
};
