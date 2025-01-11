//
// Created by Tim Apers on 29/10/2024.
//

#include "Room.h"

Room::Room() {};

void Room::render(sf::RenderWindow* window) const {
    Player* player = nullptr;
    std::vector<Entity*> others = {};
    for (Entity* entity : entities) {
        if (auto* floor = dynamic_cast<Floor*>(entity)) {floor->render(window);}
        else if (auto* p = dynamic_cast<Player*>(entity)) { player = p;}
        else { others.push_back(entity); }
    }
    for (Entity* e : others) { e->render(window); }
    if (player) { player->render(window);}
}

void Room::update(sf::Event* event) {
    for (Entity* entity : entities) {
        entity->update(event);
    }
}

std::vector<Entity *> Room::getEntites() const {
    return this->entities;
}

void Room::addEntity(Entity* entity) {
    this->entities.push_back(entity);
}

