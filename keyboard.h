#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>

class Keyboard {
    sf::RenderWindow keyboardWindow;
    sf::SoundBuffer pianoBuffer[7];
    sf::Sound pianoSound[7];
    sf::RectangleShape backgroundImage;
    sf::Texture backgroundTexture;
    std::array<sf::RectangleShape,61> keyboardNotes;
    sf::Texture whiteKeyTexture;
    sf::Texture blackKeyTexture;
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