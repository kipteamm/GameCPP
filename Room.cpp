//
// Created by Tim Apers on 29/10/2024.
//

#include "Room.h"
#include <algorithm>
#include <iostream>

Room::Room() : position() {};
Room::Room(const Position position) : position(position) {};

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
    this->player->update(event);
    for (Entity* entity : entities) {
        if (entity == this->player) continue;
        entity->update(event);

        if (!(entity->getPosition() == this->player->getPosition())) continue;
        Entity* entityToBeRemoved = entity->interacts(this->player);

        if (entityToBeRemoved == nullptr) continue;
        this->removeEntity(entityToBeRemoved);
    }
}

Position Room::getPosition() const {
    return this->position;
}


Player *Room::getPlayer() const {
    return this->player;
}


void Room::setPlayer(Player *player) {
    this->player = player;
}

void Room::removeEntity(Entity* entity) {
    this->entities.erase(std::remove(this->entities.begin(), this->entities.end(), entity), this->entities.end());

    if (entity == this->getPlayer()) {
        this->player = nullptr;
        return;
    };

    this->addEntity(new Floor(entity->getPosition()));
}


std::vector<Entity *> Room::getEntities() const {
    return this->entities;
}

void Room::addEntity(Entity* entity) {
    this->entities.push_back(entity);
}

