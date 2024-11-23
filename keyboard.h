#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>

class Keyboard {
private:
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

    // Draws each piano note
    void drawKeyboard();

    int charDetectASCII(int);

    // Draws each piano note
    void runKeyboard();

    // Draw
    void renderWindow();

};

#endif // KEYBOARD_H
