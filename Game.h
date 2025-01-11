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

    std::map<std::pair<int, int>, Room *> getRooms() { return rooms; }
    void addRoom(const std::pair<int, int> position, Room* room);
    Room* getCurrentRoom() { return currentRoom; }

    // Deze functies zal je zelf verder moeten aanvullen
    void loadMap(const std::string& filename);
    void setCurrentRoom(Room* currentRoom);


private:
    sf::RenderWindow* window;
    std::map<std::pair<int, int>, Room*> rooms;
    Room* currentRoom = nullptr;
};



#endif //GAME_H
