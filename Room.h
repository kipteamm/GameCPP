//
// Created by Tim Apers on 29/10/2024.
//

#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room {
public:
    Room();
    explicit Room(const Position position);

    // Deze functie niet aanpassen!
    void render(sf::RenderWindow* window) const;

    // Deze functie zal je zelf verder moeten aanvullen
    void update(sf::Event* event);

    Position getPosition() const;

    Player* getPlayer() const;
    void setPlayer(Player* player);
    void removeEntity(Entity* entity);

    std::vector<Entity*> getEntities() const;
    void addEntity(Entity* entity);

private:
    std::vector<Entity*> entities;
    Player* player = nullptr;
    Position position;
};



#endif //ROOM_H
