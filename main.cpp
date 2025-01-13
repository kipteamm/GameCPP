//
//  !!! Dit bestand moet je in principe NIET wijzigen !!!
//  !!!       Enkel de filename mag je aanpassen      !!!
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <direct.h>
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 700), "Game");
    Game game = Game(&window);
    game.loadMap("../resources/map2.txt");
    game.update();
    return 0;
}
