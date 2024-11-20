#include "keyboard.h"
#include <iostream>
#include <SFML/Audio.hpp>

// Constructor definition
Keyboard::Keyboard() : keyboardWindow(sf::VideoMode(800, 600), "Keyboard Window") {
    keyboardWindow.setFramerateLimit(60);
    buffer.loadFromFile("../assets/sounds/a3.mp3");
    sound.setBuffer(buffer);
    buffer1.loadFromFile("../assets/sounds/b3.mp3");
    sound1.setBuffer(buffer1);;
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
                    sound.play();
                    std::cout<< "A\n";
                    break;
                }
                case sf::Keyboard::S: {
                    sound1.play();
                    std::cout<< "S\n";
                    break;
                }
                case sf::Keyboard::D: {
                    sound.play();
                    std::cout<< "D\n";
                    break;
                }
                case sf::Keyboard::F: {
                    sound.play();
                    std::cout<< "F\n";
                    break;
                }
                case sf::Keyboard::G: {
                    sound.play();
                    std::cout<< "G\n";
                    break;
                }
                case sf::Keyboard::H: {
                    sound.play();
                    std::cout<< "H\n";
                    break;
                }
                case sf::Keyboard::J: {
                    sound.play();
                    std::cout<< "J\n";
                    break;
                }
                case sf::Keyboard::K: {
                    sound.play();
                    std::cout<< "K\n";
                    break;
                }
                case sf::Keyboard::L: {
                    sound.play();
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