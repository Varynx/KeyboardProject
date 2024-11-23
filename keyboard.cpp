#include "keyboard.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <fstream>

// Constructor definition
Keyboard::Keyboard() : keyboardWindow(sf::VideoMode(1920, 1200), "Keyboard Window") {
    keyboardWindow.setFramerateLimit(60);
    for(int pianoIter=0; pianoIter<61; pianoIter++) {
        std::string name = "../assets/sounds/note" + std::to_string(pianoIter) + ".mp3";
        pianoBuffer[pianoIter].loadFromFile(name);
        pianoSound[pianoIter].setBuffer(pianoBuffer[pianoIter]);
    }

    //loads jpg image from computer
    backgroundTexture.loadFromFile("../assets/textures/beigeBackground.jpg");
    backgroundImage.setTexture(&backgroundTexture);
    backgroundImage.setSize(sf::Vector2f(1920,1200));
    //loads in gradient for white and black key textures
    whiteKeyTexture.loadFromFile("../assets/textures/beigeToWhite.jpg");

    //WHITE KEYS INITIALIZED BELOW
    float xPositionWhiteKeys = 0;
    float yPositionWhiteKeys = 700;
    for(int iter = 0; iter < 36; iter++)
    {
        keyboardNotes[iter].setPosition(xPositionWhiteKeys,yPositionWhiteKeys);
        keyboardNotes[iter].setSize(sf::Vector2f(66.6,400));
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
        xPositionBlackKeys += 66.6;
    }
}

void Keyboard::keyboardEvent() {//test for events
    sf::Event events;
    while (keyboardWindow.pollEvent(events)) {
        if (events.type == sf::Event::MouseButtonPressed) {
            // sf::Vector2i relativePos = sf::Touch::getPosition(1, keyboardWindow);
            std::cout<<"touch is enabled"<<events.mouseButton.button<<"at position("<<events.mouseButton.x<<","<<events.mouseButton.y;

        }
    }
    //     if(events.key.code == sf::Keyboard::Escape) {
    //         keyboardWindow.close();
    //     }
    //     if(events.type == sf::Event::KeyPressed){
    //         pianoSound[events.key.code].play();
    //     }
    // }
}


void Keyboard::drawKeyboard() {
    keyboardWindow.draw(backgroundImage);
    for(int iterate = 0; iterate < 61; iterate++)
    {
        keyboardWindow.draw(keyboardNotes[iterate]);
    }
}

void Keyboard::renderWindow() {
    keyboardWindow.clear();
    drawKeyboard();
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

//Code dump
// if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && events.key.code) {

// if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && events.key.code == sf::Keyboard::B) {
//     pianoSound[events.key.code].play();
// }