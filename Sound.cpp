#include "Sound.h"
#include <array>
#include <iostream>

/**
 * Basic constructor
 */
Sound::Sound() {
    for (int pianoIter = 0; pianoIter < sizeOfPiano; pianoIter++)
    {
        std::string name = "../assets/sounds/note" + std::to_string(pianoIter) + ".mp3";
        if (!pianoBuffer[pianoIter].loadFromFile(name))
        {
            std::cerr << "Failed to load note";
        }
        pianoSound[pianoIter].setBuffer(pianoBuffer[pianoIter]);
    }

}

/**
 * Used to change volume and pitch
 */
void Sound::soundFunctions() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
        increaseVolume();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {
        decreaseVolume();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
        increasePitch();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
        decreasePitch();
    }
}

/**
 * play sound with mouse/touch
 * @param events - detects events for mouse click
 * @param keyboardNotes - Get relative position of the physical note shapes, like their boundaries
 */
void Sound::playSound(sf::Event events, std::array<sf::RectangleShape,61> keyboardNotes) {
    for(int iterNotes = 0; iterNotes < 36; iterNotes++) {
        if( ( events.mouseButton.x >=keyboardNotes[iterNotes].getPosition().x && events.mouseButton.x <= (keyboardNotes[iterNotes].getPosition().x)+53.28 )
        && (events.mouseButton.y >= 900 && events.mouseButton.y <= 1020)){
            pianoSound[iterNotes].play();
        }
    }
    for(int iterNotes = 36; iterNotes < 61; iterNotes++) {
        if( ( events.mouseButton.x >=keyboardNotes[iterNotes].getPosition().x && events.mouseButton.x <= (keyboardNotes[iterNotes].getPosition().x)+32 )  &&
             (events.mouseButton.y >= 700 && events.mouseButton.y <=860)) {
            pianoSound[iterNotes].play();
        }
    }
}

/**
 * play sound with key presses according to the sound Index in Keyboard.cpp
 * @param soundIndex - button pressed
 */
void Sound::playSound(int soundIndex) {
    pianoSound[soundIndex].play();
}

/**
 * Function to increase volume
 */
void Sound::increaseVolume() {
    pianoVolume++;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoVolume > 100) {
            pianoVolume = 100;
        }
        pianoSound[iter].setVolume(pianoVolume);
    }
}

/**
 * Function to decrease volume
 */
void Sound::decreaseVolume() {
    pianoVolume--;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoVolume < 0) {
            pianoVolume = 0;
        }
        pianoSound[iter].setVolume(pianoVolume);
    }
}

/**
 * Function to increase Pitch
 */
void Sound::increasePitch() {
    pianoPitch+=0.2;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoPitch > 4) {
            pianoPitch = 4;
        }
        pianoSound[iter].setPitch(pianoPitch);
    }
}

/**
 * Function to decrease Pitch
 */
void Sound::decreasePitch() {
    pianoPitch-=0.2;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoPitch < 0.2) {
            pianoPitch = 0.2;
        }
        pianoSound[iter].setPitch(pianoPitch);
    }
}

/**
 * Stops/Starts looping note
 * @param soundIndex - button pressed, according to sound index in Keyboard.cpp
 */
void Sound::loopSwitch(int soundIndex) {
    pianoSound[soundIndex].setLoop(!pianoSound[soundIndex].getLoop());
}