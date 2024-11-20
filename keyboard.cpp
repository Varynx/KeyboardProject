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
void Keyboard::keyboardLogic() {
    //
}

void Keyboard::renderWindow() {
    keyboardWindow.clear();

    // Draw stuff here

    keyboardWindow.display();
}

void Keyboard::runKeyboard() {
    while (keyboardWindow.isOpen()) {
        keyboardEvent();  // Handles events (keyboard, mouse)
        keyboardLogic();  //
        renderWindow();   // clear and draw
    }
}