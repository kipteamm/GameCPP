//
// Created by Tim Apers on 29/10/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Room.h"

class Game {
public:
    // Deze functies niet aanpassen!
    Game(sf::RenderWindow* window);
    void update();

    const std::map<std::pair<int, int>, Room*>& getRooms() { return rooms; }
    Room* getCurrentRoom() { return currentRoom; }

    // Deze functies zal je zelf verder moeten aanvullen
    void loadMap(const std::string& filename);
    void setCurrentRoom();


private:
    sf::RenderWindow* window;
    std::map<std::pair<int, int>, Room*> rooms;
    Room* currentRoom = nullptr;

    void loadLine(std::string& line, const int lineIndex);
    void setRoom(const std::pair<int, int>& position);
};



#endif //GAME_H
