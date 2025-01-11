//
// Created by Tim Apers on 29/10/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

struct Position {
    int x;
    int y;
};

class Entity {
public:
    explicit Entity(Position position);

    virtual void update(sf::Event* event);

    Position getPosition() const;
    void setPosition(const Position);

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
    explicit Player(Position position) : Entity(position) {};

    void update(sf::Event* event) override;

    int getAttackPower() const;
    void setAttackPower(const int attack_power);

private:
    int attackPower = 0;
};

class Weapon : public Entity {
public:
    explicit Weapon(Position position) : Entity(position) {};
};

class Wall : public Entity {
public:
    explicit Wall(Position position) : Entity(position) {};
};

class Floor : public Entity {
public:
    explicit Floor(Position position) : Entity(position) {};
};

class Enemy : public Entity {
public:
    explicit Enemy(Position position) : Entity(position) {};
};

#endif //ENTITY_H
