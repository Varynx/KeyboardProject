#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Keyboard {
    sf::RenderWindow keyboardWindow;
    // sf::SoundBuffer pianoNotes[61];
    // sf::Sound pianoNote[61];
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::SoundBuffer buffer1;
    sf::Sound sound1;


public:
    // Constructor

    Keyboard();

    // Events
    void keyboardEvent();

    //
    void keyboardLogic();

    // Draw
    void renderWindow();

    // Does all of the above
    void runKeyboard();
};

#endif // KEYBOARD_H