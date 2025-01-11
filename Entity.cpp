//
// Created by Tim Apers on 29/10/2024.
//

#include "Entity.h"
#include <iostream>

Entity::Entity() : position() {};
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

Entity* Entity::interacts(Player* player) {
    return nullptr;
}

Player::Player() : Entity(), attackPower() {};
Player::Player(const Position position, const int attackPower) : Entity(position), attackPower(attackPower) {
    this->setSprite("../resources/player.png");
}

void Player::update(sf::Event* event) {
    Position position = this->getPosition();
    this->setPreviousPosition(position);
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

void Player::setPreviousPosition(Position position) {
    this->previousPosition = position;
}

Position Player::getPreviousPosition() const {
    return this->previousPosition;
}

int Player::getAttackPower() const {
    return this->attackPower;
}

void Player::setAttackPower(const int attack_power) {
    this->attackPower = attack_power;
}

Weapon::Weapon() : Entity() {};
Weapon::Weapon(const Position position) : Entity(position) {
    this->setSprite("../resources/weapon.png");
}

Entity* Weapon::interacts(Player* player) {
    player->setAttackPower(1);
    return this;
}

Wall::Wall() : Entity() {};
Wall::Wall(const Position position) : Entity(position) {
    this->setSprite("../resources/wall.png");
}

Entity* Wall::interacts(Player* player) {
    const int posX = player->getPosition().x % 700;
    const int posY = player->getPosition().y % 700;

    if (posX == 0) {
        player->setPosition(Position{player->getPosition().x + 100, player->getPosition().y});
        return nullptr;
    }

    if (posX == 600) {
        player->setPosition(Position{player->getPosition().x - 100, player->getPosition().y});
        return nullptr;
    }

    if (posY == 0) {
        player->setPosition(Position{player->getPosition().x, player->getPosition().y + 100});
        return nullptr;
    }

    if (posY == 600) {
        player->setPosition(Position{player->getPosition().x, player->getPosition().y - 100});
        return nullptr;
    };

    return nullptr;
}

Floor::Floor() : Entity() {};
Floor::Floor(const Position position) : Entity(position) {
    this->setSprite("../resources/floor.png");
}

Enemy::Enemy() : Entity() {};
Enemy::Enemy(const Position position) : Entity(position) {
    this->setSprite("../resources/enemy.png");
}

Entity* Enemy::interacts(Player *player) {
    if (player->getAttackPower() == 1) return this;
    player->setPosition(player->getPreviousPosition());

    return nullptr;
}
