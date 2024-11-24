#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <array>

class Sound {
    int sizeOfPiano = 61;
    std::array<sf::SoundBuffer,61> pianoBuffer;
    std::array<sf::Sound,61> pianoSound;

    int pianoVolume=100;
    float pianoPitch = 1.0;
public:
    // Constructor
    Sound();

    // Events
    void playSound(sf::Event, std::array<sf::RectangleShape,61>);
    void playSound(int soundIndex);

    void soundFunctions();

    void increaseVolume();

    void decreaseVolume();

    void increasePitch();

    void decreasePitch();

    void loopSwitch(int loopNote);


};

#endif //SOUND_H
