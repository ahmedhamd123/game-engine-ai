#include "game_registry.h"
#include <iostream>

void GameRegistry::addGame(const std::string &gameName) {
    registeredGames.push_back(gameName);
}

void GameRegistry::displayGames() {
    std::cout << "Games built with this engine:" << std::endl;
    for (const auto &game : registeredGames) {
        std::cout << "- " << game << std::endl;
    }
}
