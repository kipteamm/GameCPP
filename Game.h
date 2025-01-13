//
// Created by Tim Apers on 29/10/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Room.h"
#include <map>

class Game {
public:
    // Deze functies niet aanpassen!
    Game();
    Game(sf::RenderWindow* window);
    void update();

    std::vector<Room*> getRooms() const;
    Room* getCurrentRoom() { return currentRoom; }

    // Deze functies zal je zelf verder moeten aanvullen
    void loadMap(const std::string& filename);
    void setCurrentRoom();

    void debug();


private:
    sf::RenderWindow* window;
    std::map<std::pair<int, int>, Room*> rooms;
    Room* currentRoom = nullptr;

    void loadLine(std::string& line, const int lineIndex);
    bool setRoom(const std::pair<int, int>& position);
};



#endif //GAME_H
