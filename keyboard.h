#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Keyboard {
private:
    sf::RenderWindow keyboardWindow;
    sf::SoundBuffer buffer;
    sf::Sound sound;

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