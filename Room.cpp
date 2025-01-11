//
// Created by Tim Apers on 29/10/2024.
//

#include "Room.h"

#include <iostream>

Room::Room(Position position) : position(position) {};

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

        if (entity->getPosition() == this->player->getPosition()) entity->interacts(this->player);
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

void Room::removePlayer() {
    this->entities.erase(std::remove(this->entities.begin(), this->entities.end(), this->player), this->entities.end());
    this->player = nullptr;
}


std::vector<Entity *> Room::getEntites() const {
    return this->entities;
}

void Room::addEntity(Entity* entity) {
    this->entities.push_back(entity);
}

