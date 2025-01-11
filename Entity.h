//
// Created by Tim Apers on 29/10/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

struct Position {
    int x;
    int y;

    bool operator == (const Position& other) const {
        return x == other.x && y == other.y;
    }
};

class Player;

class Entity {
public:
    explicit Entity(Position position);

    virtual void update(sf::Event* event);

    Position getPosition() const;
    void setPosition(const Position);

    virtual void interacts(Player* player);

    // Onderstaande functies niet aanpassen!
    void setSprite(const std::string &img_path);
    void render(sf::RenderWindow *painter);
    ~Entity() = default;

private:
    Position position;
    sf::Sprite sprite;
    sf::Texture texture;
};


class Player : public Entity {
public:
    explicit Player(Position position);

    void update(sf::Event* event) override;

    int getAttackPower() const;
    void setAttackPower(const int attack_power);

private:
    int attackPower = 0;
};

class Weapon : public Entity {
public:
    explicit Weapon(Position position);
};

class Wall : public Entity {
public:
    explicit Wall(Position position);

    void interacts(Player* player);
};

class Floor : public Entity {
public:
    explicit Floor(Position position);
};

class Enemy : public Entity {
public:
    explicit Enemy(Position position);
};

#endif //ENTITY_H
