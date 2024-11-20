#include "keyboard.h"
#include <iostream>
#include <SFML/Audio.hpp>

// Constructor definition
Keyboard::Keyboard() : keyboardWindow(sf::VideoMode(800, 600), "Keyboard Window") {
    keyboardWindow.setFramerateLimit(60);
    buffer.loadFromFile("../assets/sounds/a3.mp3");
    sound.setBuffer(buffer);
}

void Keyboard::keyboardEvent() {//test for events
    sf::Event events{};

    while (keyboardWindow.pollEvent(events)) {
        if (events.type == sf::Event::Closed || events.key.code == sf::Keyboard::Escape) {
            keyboardWindow.close();
        }

        if (events.type == sf::Event::KeyPressed) {
            if (events.key.code == sf::Keyboard::A) {
                std::cout << "A\n";
                sound.play();
            }
            if (events.key.code == sf::Keyboard::S) {
                std::cout << "S\n";
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