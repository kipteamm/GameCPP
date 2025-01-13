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
    Entity();
    explicit Entity(Position position);

    virtual void update(sf::Event* event, Position roomPosition);

    Position getPosition() const;
    void setPosition(const Position);

    virtual Entity* interacts(Player* player);

    // Onderstaande functies niet aanpassen!
    void setSprite(const std::string &img_path);
    void render(sf::RenderWindow *painter);
    ~Entity() = default;

private:
    Position position{};
    sf::Sprite sprite;
    sf::Texture texture;
};


class Player : public Entity {
public:
    Player();
    explicit Player(Position position, const int attackPower);

    void update(sf::Event* event, Position roomPosition) override;
    void setPreviousPosition(Position position);
    Position getPreviousPosition() const;

    int getAttackPower() const;
    void setAttackPower(const int attack_power);

private:
    Position previousPosition = Position{0,0};
    int attackPower = 0;
};

class Weapon : public Entity {
public:
    Weapon();
    explicit Weapon(Position position);

    Entity* interacts(Player* player);
};

class Wall : public Entity {
public:
    Wall();
    explicit Wall(Position position);

    Entity* interacts(Player* player);
};

class Floor : public Entity {
public:
    Floor();
    explicit Floor(Position position);
};

class Enemy : public Entity {
public:
    Enemy();
    explicit Enemy(Position position);

    Entity* interacts(Player* player);
};

#endif //ENTITY_H
