//
// Created by Tim Apers on 29/10/2024.
//

#include <fstream>
#include "Game.h"

#include <cmath>
#include <iostream>

Game::Game(sf::RenderWindow* window): window(window), rooms() {}

void Game::update() {
    setCurrentRoom();
    this->window->clear();
    if (currentRoom) { currentRoom->render(this->window); }
    this->window->display();
    while (window->isOpen()) {
        sf::Event event;

        // Wait for event to fire
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            } else if (event.type == sf::Event::KeyPressed) {
                currentRoom->update(&event);
                setCurrentRoom();
                this->window->clear();
                currentRoom->render(this->window);
                this->window->display();
            }
        }
    }

}

void Game::loadLine(std::string& line, const int lineIndex) {
    const int roomY = std::floor(lineIndex / 7);

    for (int lineX = 0; lineX < line.size(); lineX++) {
        const int roomX = std::floor(lineX / 7);
        std::pair position{roomX, roomY};
        Room* room = nullptr;

        if (auto it = this->rooms.find(position); it != this->rooms.end()) {
            room = it->second;
        } else {
            room = new Room();
            this->rooms[position] = room;
        }

        Position entityPosition{(lineIndex % 7) * 100, (lineX % 7) * 100};

        switch (line[lineX]) {
            case '#':
                room->addEntity(new Wall(entityPosition));
                break;
            case '_':
                room->addEntity(new Floor(entityPosition));
                break;
            case '%':
                room->addEntity(new Enemy(entityPosition));
            break;
            case '!':
                room->addEntity(new Weapon(entityPosition));
                break;
            case '@':
                room->addEntity(new Player(entityPosition));
                room->addEntity(new Floor(entityPosition));
                this->currentRoom = room;
                break;
            default:
                std::cout << "Unrecognized character" << std::endl;
                break;
        }
    }
}

void Game::loadMap(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return;
    }

    int lineIndex = 0;
    while (std::getline(file, line)) {
        this->loadLine(line, lineIndex);
        lines.push_back(line);
        lineIndex++;
    }

    file.close();
}

void Game::setCurrentRoom() {}