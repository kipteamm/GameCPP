//
// Created by Tim Apers on 29/10/2024.
//

#include "Entity.h"
#include <iostream>

Entity::Entity(const Position position) : position(position) {};


void Entity::setSprite(const std::string& img_path) {
    if (!this->texture.loadFromFile(img_path)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    sf::Vector2u size = this->texture.getSize();
    float scaleX = 100.0f / size.x;
    float scaleY = 100.0f / size.y;
    this->sprite.setScale(scaleX, scaleY);
}

void Entity::render(sf::RenderWindow *window) {
    sprite.setPosition(position.x%700, position.y%700);
    window->draw(sprite);
}

void Entity::update(sf::Event* event) {

}

Position Entity::getPosition() const {
    return this->position;
}

void Entity::setPosition(const Position position) {
    this->position = position;
}

void Entity::interacts(Player* player) {

}

Player::Player(const Position position) : Entity(position) {
    this->setSprite("../resources/player.png");
}

void Player::update(sf::Event* event) {
    Position position = this->getPosition();
    switch (event->key.code) {
        case sf::Keyboard::Left:
            this->setPosition(Position{position.x - 100, position.y});
            break;
        case sf::Keyboard::Right:
            this->setPosition(Position{position.x + 100, position.y});
            break;
        case sf::Keyboard::Up:
            this->setPosition(Position{position.x, position.y - 100});
            break;
        case sf::Keyboard::Down:
            this->setPosition(Position{position.x, position.y + 100});
            break;
        default: break;
    }
}

int Player::getAttackPower() const {
    return this->attackPower;
}

void Player::setAttackPower(const int attack_power) {
    this->attackPower = attack_power;
}

Weapon::Weapon(const Position position) : Entity(position) {
    this->setSprite("../resources/weapon.png");
}

Wall::Wall(const Position position) : Entity(position) {
    this->setSprite("../resources/wall.png");
}

void Wall::interacts(Player* player) {
    if (this->getPosition().x == 0) {
        player->setPosition(Position{player->getPosition().x + 100, player->getPosition().y});
        return;
    }

    if (this->getPosition().x == 600) {
        player->setPosition(Position{player->getPosition().x - 100, player->getPosition().y});
        return;
    }

    if (this->getPosition().y == 0) {
        player->setPosition(Position{player->getPosition().x, player->getPosition().y + 100});
        return;
    }

    if (this->getPosition().y != 600) return;
    player->setPosition(Position{player->getPosition().x, player->getPosition().y - 100});
}

Floor::Floor(const Position position) : Entity(position) {
    this->setSprite("../resources/floor.png");
}

Enemy::Enemy(const Position position) : Entity(position) {
    this->setSprite("../resources/enemy.png");
}