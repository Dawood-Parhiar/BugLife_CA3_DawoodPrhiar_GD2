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
#include "SuperBug.h"

class Hopper;
class Crawler;

using namespace std;


void drawMenu();
void renderWindow();
void chooseOption();

void findBugById();

void bugPathHistory();

void cellsWithBugs();

void runSimulation();

void lifeHistoryToFile();

void drawBugsOnBoard(sf::RenderWindow& window);


//create a global board object
Board board;
int main() {

    chooseOption();
    return 0;
}

void renderWindow() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Bug Life");
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
                    board.fight();//fight the bugs
                }else if(event.key.code == sf::Keyboard::Enter)
                {
                    //if the user presses the enter key
                    //the simulation will run
                    runSimulation();

                }
                else if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
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
        if(dynamic_cast<Hopper*>(bug_vector[i]) != nullptr && bug_vector[i]->isAlive())
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
        }else if(dynamic_cast<SuperBug*>(bug_vector[i]) != nullptr)
        {
            sf::CircleShape superBug(50.f);
            sf::Texture texture;
            texture.loadFromFile("images/superbug.png");
            superBug.setTexture(&texture);
            superBug.setPosition(bug_vector[i]->getPosition().first * 100, bug_vector[i]->getPosition().second * 100);
            window.draw(superBug);

            //in the events of a superbug, draw a circle around the superbug
            sf::CircleShape circle(60.f);
            circle.setFillColor(sf::Color::Transparent);
            circle.setOutlineThickness(5);
            circle.setOutlineColor(sf::Color::Red);
            circle.setPosition(bug_vector[i]->getPosition().first * 100, bug_vector[i]->getPosition().second * 100);
            window.draw(circle);

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
        drawMenu();
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
    //get the vector of bugs
    std::vector<Bug*>& bug_vector = board.getBugs();
    //loop through the vector and print the position  of each bug
    for(int i = 0; i < bug_vector.size(); i++)
    {
        //get the current date and time
        time_t now = time(0);
        //convert now to string form
        char* dt = ctime(&now);
        //open the file
        std::ofstream file;
        file.open("buglife.txt", ios::app);
        //write the date and time to the file
        file << dt << endl;
        //close the file
        file.close();
    }


}


void runSimulation() {
    cout << "Running simulation" << endl;
    board.shakeBoard();
    //shake the board every second for infinite time
    bool exit = false;
    for(int i= 0; i < 1000; i++ )
    {
        board.shakeBoard();
        sleep(1);
        //if only one bug is left, exit the loop
        if(board.getBugs().size() == 1)
        {
            exit = true;
        }

    }
}

void cellsWithBugs() {
    cout << "Displaying cells with bugs" << endl;
    //get the vector of bugs
    std::vector<Bug*>& bug_vector = board.getBugs();
    //loop through the vector and print the position  of each bug
    for(int i = 0; i < bug_vector.size(); i++)
    {
        cout << "Bug " << bug_vector[i]->getId() << " is in cell " << bug_vector[i]->getPosition().first << ", " << bug_vector[i]->getPosition().second << endl;
    }

}

void bugPathHistory() {
    cout << "Displaying bug path history" << endl;
    //get the vector of bugs
    std::vector<Bug*>& bug_vector = board.getBugs();
    //loop through the vector and print the path history of each bug
    for(int i = 0; i < bug_vector.size(); i++)
    {
        cout << "Bug " << bug_vector[i]->getId() << " path history: " << endl;
        bug_vector[i]->getPath().push_back(bug_vector[i]->getPosition());
    }

}


void findBugById() {
    cout << "Finding bug by id" << endl;
    //get the vector of bugs
    std::vector<Bug*>& bug_vector = board.getBugs();
    //get the id of the bug to find
    int id;
    cout << "Enter the id of the bug to find" << endl;
    cin >> id;
    //loop through the vector and find the bug with the given id
    for(int i = 0; i < bug_vector.size(); i++)
    {
        if(bug_vector[i]->getId() == id)
        {
            if(dynamic_cast<Hopper*>(bug_vector[i]) != nullptr)
            {
                cout << "Hopper id: " << bug_vector[i]->getId() << endl;
                cout << "Hopper position: " << bug_vector[i]->getPosition().first << ", " << bug_vector[i]->getPosition().second << endl;
                cout << "Hopper Size: " << bug_vector[i]->getSize() << endl;
                cout << "Hopper direction: " << bug_vector[i]->getDirection() << endl;
                cout << "Hopper Hop Length: " << endl;
                cout << "Hopper path history: " << endl;
                for(int j = 0; j < bug_vector[i]->getPath().size(); j++)
                {
                    bug_vector[i]->getPath().push_back(bug_vector[i]->getPosition());

                }
            }
            else if(dynamic_cast<Crawler*>(bug_vector[i]) != nullptr)
            {
                cout << "Bug " << bug_vector[i]->getId() << " is a Crawler" << endl;
                cout << "Crawler id: " << bug_vector[i]->getId() << endl;
                cout << "Crawler position: " << bug_vector[i]->getPosition().first << ", " << bug_vector[i]->getPosition().second << endl;
                cout << "Crawler Size: " << bug_vector[i]->getSize() << endl;
                cout << "Crawler direction: " << bug_vector[i]->getDirection() << endl;
                cout << "Crawler path history: " << endl;
                for(int j = 0; j < bug_vector[i]->getPath().size(); j++)
                {
                    bug_vector[i]->getPath().push_back(bug_vector[i]->getPosition());

                }
                bug_vector[i]->getPath();

            }else if(dynamic_cast<SuperBug*>(bug_vector[i]) != nullptr)
            {
                cout << "Bug " << bug_vector[i]->getId() << " is a SuperBug" << endl;
                cout << "SuperBug id: " << bug_vector[i]->getId() << endl;
                cout << "SuperBug position: " << bug_vector[i]->getPosition().first << ", " << bug_vector[i]->getPosition().second << endl;
                cout << "SuperBug Size: " << bug_vector[i]->getSize() << endl;
                cout << "SuperBug direction: " << bug_vector[i]->getDirection() << endl;
                cout << "SuperBug path history: " << endl;
                for(int j = 0; j < bug_vector[i]->getPath().size(); j++)
                {
                    bug_vector[i]->getPath().push_back(bug_vector[i]->getPosition());


                }
                bug_vector[i]->getPath();
            }
            else
            {
                cout << "Bug not found" << endl;
            }
        }

    }

}



