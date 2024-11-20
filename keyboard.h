#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Keyboard {
    sf::RenderWindow keyboardWindow;
    sf::SoundBuffer pianoBuffer[7];
    sf::Sound pianoSound[7];

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