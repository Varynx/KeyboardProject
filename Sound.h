#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Sound {
    sf::SoundBuffer pianoBuffer[61];
    sf::Sound pianoSound[61];
    int pianoVolume=100;
    float pianoPitch = 1.0;
public:
    // Constructor
    Sound();

    // Events
    void playSound(sf::Event, std::array<sf::RectangleShape,61>);

    void increaseVolume();

    void decreaseVolume();

    void increasePitch();

    void decreasePitch();

    void loopSwitch(int loopNote);


};

#endif //SOUND_H
