#include "Sound.h"
#include <array>
#include <iostream>

Sound::Sound() {
    for (int pianoIter = 0; pianoIter < 61; pianoIter++)
    {
        std::string name = "../assets/sounds/note" + std::to_string(pianoIter) + ".mp3";
        if (!pianoBuffer[pianoIter].loadFromFile(name))
        {
            std::cerr << "Failed to load note";
        }
        pianoSound[pianoIter].setBuffer(pianoBuffer[pianoIter]);
    }

}

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

void Sound::playSound(sf::Event events, std::array<sf::RectangleShape,61> keyboardNotes) {//play sound with mouse/touch
    for(int iterNotes = 0; iterNotes < 36; iterNotes++) {
        if( (events.mouseButton.x >=keyboardNotes[iterNotes].getPosition().x && events.mouseButton.x <= keyboardNotes[iterNotes+1].getPosition().x)
        && (events.mouseButton.y >= 900 && events.mouseButton.y <= 1100)){
            pianoSound[iterNotes].play();
        }
    }
    for(int iterNotes = 36; iterNotes < 61; iterNotes++) {
        if( ( events.mouseButton.x >=keyboardNotes[iterNotes].getPosition().x && events.mouseButton.x <= (keyboardNotes[iterNotes].getPosition().x)+45.3 )  &&
             (events.mouseButton.y >= 700 && events.mouseButton.y <= 900)) {
            pianoSound[iterNotes].play();
        }
    }
}
void Sound::playSound(int soundIndex) {//play sound with key presses
    pianoSound[soundIndex].play();
}

void Sound::increaseVolume() {
    pianoVolume++;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoVolume > 100) {
            pianoVolume = 100;
        }
        pianoSound[iter].setVolume(pianoVolume);
    }
}

void Sound::decreaseVolume() {
    pianoVolume--;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoVolume < 0) {
            pianoVolume = 0;
        }
        pianoSound[iter].setVolume(pianoVolume);
    }
}
void Sound::increasePitch() {
    pianoPitch+=0.2;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoPitch > 4) {
            pianoPitch = 4;
        }
        pianoSound[iter].setPitch(pianoPitch);
    }
}

void Sound::decreasePitch() {
    pianoPitch-=0.2;
    for(int iter = 0; iter < sizeOfPiano; iter++) {
        if(pianoPitch < 0.2) {
            pianoPitch = 0.2;
        }
        pianoSound[iter].setPitch(pianoPitch);
    }
}

void Sound::loopSwitch(int loopNote) {
    pianoSound[loopNote].setLoop(!pianoSound[loopNote].getLoop());
}