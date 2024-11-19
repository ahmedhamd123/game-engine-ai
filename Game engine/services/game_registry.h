#pragma once
#include <vector>
#include <string>

class GameRegistry {
private:
    std::vector<std::string> registeredGames;

public:
    void addGame(const std::string &gameName);
    void displayGames();
};