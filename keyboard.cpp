#include "keyboard.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <fstream>

// Constructor definition
Keyboard::Keyboard() : keyboardWindow(sf::VideoMode(800, 600), "Keyboard Window") {
    keyboardWindow.setFramerateLimit(60);
    for(int pianoIter=0; pianoIter<7; pianoIter++) {
        std::string name = "../assets/sounds/a" + std::to_string(pianoIter+1) + ".mp3";
        // std::ifstream file(name);
        pianoBuffer[pianoIter].loadFromFile(name);
        pianoSound[pianoIter].setBuffer(pianoBuffer[pianoIter]);
    }

    //loads jpg image from computer (change filepath as needed)
    backgroundTexture.loadFromFile("../assets/beigeBackground.jpg");
    backgroundImage.setTexture(&backgroundTexture);
    backgroundImage.setSize(sf::Vector2f(2400,1600));
    //loads in gradient for white and black key textures (change filepath as needed)
    whiteKeyTexture.loadFromFile("../assets/beigeToWhite.jpg");
    // blackKeyTexture.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/blackGradientTransparent.jpg");
    //WHITE KEYS INITIALIZED BELOW
    float xPositionWhiteKeys = 0;
    float yPositionWhiteKeys = 700;
    for(int iter = 0; iter < 36; iter++)
    {
        keyboardNotes[iter].setPosition(xPositionWhiteKeys,yPositionWhiteKeys);
        keyboardNotes[iter].setSize(sf::Vector2f(66.6,400));
        keyboardNotes[iter].setFillColor(sf::Color::White);
        keyboardNotes[iter].setOutlineThickness(2);
        keyboardNotes[iter].setOutlineColor(sf::Color::Black);
        keyboardNotes[iter].setTexture(&whiteKeyTexture);
        xPositionWhiteKeys += 66.6;
    }
    //BLACK KEYS INITIALIZED BELOW
    float xPositionBlackKeys = 45.3;
    float yPositionBlackKeys = 700;
    std::set<int> xPositionSkip = {38,41,43,46,48,51,53,56,58};
    for(int iterator = 36; iterator < 61; iterator++)
    {
        if(xPositionSkip.find(iterator) != xPositionSkip.end())
        {
            xPositionBlackKeys += 66.6;
        }
        keyboardNotes[iterator].setPosition(xPositionBlackKeys,yPositionBlackKeys);
        keyboardNotes[iterator].setSize(sf::Vector2f(40,200));
        keyboardNotes[iterator].setFillColor(sf::Color::Black);
        keyboardNotes[iterator].setOutlineThickness(2);
        keyboardNotes[iterator].setOutlineColor(sf::Color::Black);
        keyboardNotes[iterator].setTexture(&blackKeyTexture);
        xPositionBlackKeys += 66.6;
    }
}

void Keyboard::keyboardEvent() {//test for events
    sf::Event events;
    while (keyboardWindow.pollEvent(events)) {
        if(events.type == sf::Event::KeyPressed) {
            switch(events.key.code) {
                case sf::Keyboard::Escape: {
                    keyboardWindow.close();
                    break;
                }
                case sf::Keyboard::A: {
                    pianoSound[0].play();
                    std::cout<< "A\n";
                    break;
                }
                case sf::Keyboard::S: {
                    pianoSound[1].play();
                    std::cout<< "S\n";
                    break;
                }
                case sf::Keyboard::D: {
                    pianoSound[2].play();
                    std::cout<< "D\n";
                    break;
                }
                case sf::Keyboard::F: {
                    pianoSound[3].play();
                    std::cout<< "F\n";
                    break;
                }
                case sf::Keyboard::G: {
                    pianoSound[4].play();
                    std::cout<< "G\n";
                    break;
                }
                case sf::Keyboard::H: {
                    pianoSound[5].play();
                    std::cout<< "H\n";
                    break;
                }
                case sf::Keyboard::J: {
                    pianoSound[6].play();
                    std::cout<< "J\n";
                    break;
                }
                case sf::Keyboard::K: {
                    // pianoSound[7].play();
                    std::cout<< "K\n";
                    break;
                }
                case sf::Keyboard::L: {
                    // pianoSound[8].play();
                    std::cout<< "L\n";
                    break;
                }

            }
        }
    }
}

void Keyboard::renderWindow() {
    keyboardWindow.clear();

    // Draw stuff here

    keyboardWindow.display();
}

void Keyboard::runKeyboard() {
    while (keyboardWindow.isOpen()) {
        keyboardEvent();  // Handles events (keyboard, mouse)
        renderWindow();   // clear and draw
    }
}
// SFML has internal events, which are stored somewhere. The object named events we created stores the events that come from the pollEvent function,
// which continuously checks for events in order. Now, the object events of type sf::Event contains data that we can compare to our existing items,
// such as Close, Escape, or KeyboardPressed