#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Bug.h"
#include "Board.h"
#include "Hopper.h"
#include "Crawler.h"

class Hopper;
class Crawler;

using namespace std;


void drawMenu();
void renderWindow();
void chooseOption();
void loadFromFile();

void displayAllBugs();

void findBugById();

void shakeBoard();

void bugPathHistory();

void cellsWithBugs();

void runSimulation();

void lifeHistoryToFile();

void drawBugsOnBoard(sf::RenderWindow& window);

[[maybe_unused]]

//create a global board object
Board board;
int main() {

    drawMenu();
    chooseOption();
    return 0;
}

void renderWindow() {
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
            if(event.type == sf::Event::KeyPressed)
            {
                //if the user presses the space bar
                //the board will be shaken
                if(event.key.code == sf::Keyboard::Space)
                {
                    board.shakeBoard();
                }
            }
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
            }

        }
        //draw the bugs
        drawBugsOnBoard(window);
        // end the current frame
        window.display();
    }
}
void drawBugsOnBoard(sf::RenderWindow& window) {

    std::vector<Bug*>& bug_vector = board.getBugs();//

    for (int i = 0; i < bug_vector.size(); i++)
    {
        if(dynamic_cast<Hopper*>(bug_vector[i]) != nullptr)
        {
            sf::CircleShape shape(50.f);
            sf::Texture texture;
            texture.loadFromFile("images/hopper2.png");
            shape.setTexture(&texture);
            shape.setPosition(bug_vector[i]->getPosition().first * 100, bug_vector[i]->getPosition().second * 100);
            window.draw(shape);
        }
        else if(dynamic_cast<Crawler*>(bug_vector[i]) != nullptr)
        {
            sf::CircleShape shape(50.f);
            sf::Texture texture;
            texture.loadFromFile("images/crawler.png");
            shape.setTexture(&texture);
            shape.setPosition(bug_vector[i]->getPosition().first * 100, bug_vector[i]->getPosition().second * 100);
            window.draw(shape);
        }
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
void chooseOption()
{
    bool exit = false;
    while(!exit) {
        cout << "Please choose an option" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Loading from file" << endl;
                board.loadFromFile();
                renderWindow();
                break;
            case 2:
                board.displayAllBugs();
                break;
            case 3:
                findBugById();
                break;
            case 4:
                board.shakeBoard();
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
    cout << "Running simulation" << endl;
    board.shakeBoard();
    //shake the board every second for infinite time
    while(true)
    {
        board.shakeBoard();
        sleep(1);
    }
}

void cellsWithBugs() {
    cout << "Displaying cells with bugs" << endl;

}

void bugPathHistory() {

}


void findBugById() {
    cout << "Finding bug by id" << endl;

}



