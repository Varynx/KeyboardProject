#include "Sound.h"
#include <array>
#include <iostream>

/**
 * SoundBase constructor to initialize volume and pitch
 */
SoundBase::SoundBase() : soundVolume(100), soundPitch(1.0f) {}
//Defined virtual functions
void SoundBase::increaseVolume() {}

void SoundBase::decreaseVolume() {}

void SoundBase::increasePitch() {}

void SoundBase::decreasePitch() {}

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
void Sound::playSound(sf::Event events, std::array<sf::RectangleShape,61> keyboardNotes) {//play sound with mouse/touch
    for(int iterNotes = 0; iterNotes < 36; iterNotes++) {
        if( ( events.mouseButton.x >=keyboardNotes[iterNotes].getPosition().x && events.mouseButton.x <= (keyboardNotes[iterNotes].getPosition().x)+53.28 )
        && (events.mouseButton.y >= 860 && events.mouseButton.y <= 1020)){
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
    soundVolume++;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(soundVolume > 100) {
            soundVolume = 100;
        }
        pianoSound[iter].setVolume(soundVolume);
    }
}

/**
 * Function to decrease volume
 */
void Sound::decreaseVolume() {
    soundVolume--;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(soundVolume < 0) {
            soundVolume = 0;
        }
        pianoSound[iter].setVolume(soundVolume);
    }
}

/**
 * Function to increase Pitch
 */
void Sound::increasePitch() {
    soundPitch+=0.2;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(soundPitch > 4) {
            soundPitch = 4;
        }
        pianoSound[iter].setPitch(soundPitch);
    }
}

/**
 * Function to decrease Pitch
 */
void Sound::decreasePitch() {
    soundPitch-=0.2;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(soundPitch < 0.2) {
            soundPitch = 0.2;
        }
        pianoSound[iter].setPitch(soundPitch);
    }
}

/**
 * Stops/Starts looping note
 * @param soundIndex - button pressed, according to sound index in Keyboard.cpp
 */
void Sound::loopSwitch(int soundIndex) {
    pianoSound[soundIndex].setLoop(!pianoSound[soundIndex].getLoop());
}