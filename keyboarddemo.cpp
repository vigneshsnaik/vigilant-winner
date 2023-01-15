#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::SoundBuffer buffer;
    buffer.loadFromSineWave(1000, 1, 44100); // create buffer with 1000Hz sine wave
    sf::Sound sound(buffer);

    while (true)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            sound.play(); // play sound
        }
        else
        {
            sound.stop(); // stop sound when key is released
        }
    }
    return 0;
}
