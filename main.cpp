#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Bug.h"

using namespace std;

void drawGrid(sf::RenderWindow &window);

void drawMenu();

int main() {

    vector<Bug*> bug_vector;



    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            drawGrid(window);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }


}

void drawMenu() {
    //draw the below menu in sfml
//    Menu Items
//    1. Initialize Bug Board (load data from file)
//    2. Display all Bugs
//    3. Find a Bug (given an id)
//    4. Tap the Bug Board (causes move all, then fight/eat)
//    5. Display Life History of all Bugs (path taken)
//    6. Display all Cells listing their Bugs
//    7. Run simulation (generates a Tap every second)
//    8. Exit (write Life History of all Bugs to file)



}

