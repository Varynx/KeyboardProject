#include "keyboard.h"
#include <iostream>
#include <SFML/Audio.hpp>

// Constructor definition
Keyboard::Keyboard() : keyboardWindow(sf::VideoMode(800, 600), "Keyboard Window") 
{
    keyboardWindow.setFramerateLimit(60);
    buffer.loadFromFile("../assets/sounds/a3.mp3");
    sound.setBuffer(buffer);
    buffer1.loadFromFile("../assets/sounds/b3.mp3");
    sound1.setBuffer(buffer1);

    //loads jpg image from computer (change filepath as needed)
    backgroundTexture.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/randomMinimalistBackground.jpg");
    backgroundImage.setTexture(&backgroundTexture);
    backgroundImage.setSize(sf::Vector2f(2400,1600));

    //loads in gradient for white and black key textures (change filepath as needed)
    whiteKeyTexture.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/beigeToWhite.jpg");
    blackKeyTexture.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/blackGradientTransparent.jpg");

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
