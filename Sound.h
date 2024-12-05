#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <array>

class SoundBase {
protected:
    int soundVolume;
    float soundPitch;

public:
    SoundBase();

    virtual void increaseVolume();
    virtual void decreaseVolume();
    virtual void increasePitch();
    virtual void decreasePitch();
};

class Sound : public SoundBase {
private:
    int sizeOfPiano = 61;
    std::array<sf::SoundBuffer, 61> pianoBuffer;
    std::array<sf::Sound, 61> pianoSound;

public:
    Sound();

    void playSound(sf::Event events, std::array<sf::RectangleShape, 61> keyboardNotes);
    void playSound(int soundIndex);
    void loopSwitch(int soundIndex);

    void soundFunctions();

    void increaseVolume() override;
    void decreaseVolume() override;
    void increasePitch() override;
    void decreasePitch() override;
};

#endif //SOUND_H