#include <iostream>
#include <fstream>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Bug.h"
#include "Board.h"

class Hopper;
class Crawler;

using namespace std;


void drawMenu();
void renderWindow(Board& board);
void chooseOption(Board &board);
void loadFromFile();

void displayAllBugs();

void findBugById();

void shakeBoard();

void bugPathHistory();

void cellsWithBugs();

void runSimulation();

void lifeHistoryToFile();

[[maybe_unused]]


int main() {
    Board board;


    renderWindow(board);
    drawMenu();
    chooseOption(board);


    return 0;
}

void renderWindow(Board& board) {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        // draw a grid of 10 x 10 squares
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                sf::RectangleShape rectangle(sf::Vector2f(100, 100));
                rectangle.setOutlineColor(sf::Color::Black);
                rectangle.setOutlineThickness(1);
                rectangle.setPosition(i * 100, j * 100);
                window.draw(rectangle);
                //place the bugs on the grid




            }

        }
        //draw the bugs

        std::vector<Bug*>& bug_vector = board.getBugs();

        for (int i = 0; i < bug_vector.size(); i++) {
            sf::CircleShape shape(50.f);
            shape.setFillColor(sf::Color::Blue);
            shape.setPosition(bug_vector[i]->getPosition().first * 100, bug_vector[i]->getPosition().second * 100);
            window.draw(shape);
        }
        int x =2;
        int y=2;

        sf::CircleShape shape(50.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x*100, y*100);
        window.draw(shape);



        // end the current frame
        window.display();
    }
}

void drawMenu() {
        cout << "Welcome to BugLife" << endl;
        cout << "Menu Items" << endl;
        cout << "1. Initialize Bug Board (load data from file)" << endl;
        cout << "2. Display all Bugs" << endl;
        cout << "3. Find a Bug (given an id)" << endl;
        cout << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
        cout << "5. Display Life History of all Bugs (path taken)" << endl;
        cout << "6. Display all Cells listing their Bugs" << endl;
        cout << "7. Run simulation (generates a Tap every second)" << endl;
        cout << "8. Exit (write Life History of all Bugs to file)" << endl;

}
void chooseOption(Board &board) {
    //Board board;

    bool exit = false;
    while(!exit) {
        cout << "Please choose an option" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Loading from file" << endl;
                board.loadFromFile();
                break;
            case 2:
                board.displayAllBugs();
                break;
            case 3:
                findBugById();
                break;
            case 4:
                shakeBoard();
                break;
            case 5:
                bugPathHistory();
                break;
            case 6:
                cellsWithBugs();
                break;
            case 7:
                runSimulation();
                break;
            case 8:
                cout << "Exiting" << endl;
                lifeHistoryToFile();
                exit = true;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
}

void lifeHistoryToFile() {
    cout << "Writing life history to file" << endl;


}

void runSimulation() {

}

void cellsWithBugs() {
    cout << "Displaying cells with bugs" << endl;

}

void bugPathHistory() {

}

void shakeBoard() {
    cout << "Shaking board" << endl;


}

void findBugById() {
    cout << "Finding bug by id" << endl;

}

void displayAllBugs() {
    cout << "Displaying all bugs" << endl;

}


