#ifndef AUDIO_HANDLER_HPP
#define AUDIO_HANDLER_HPP

#include <SFML/Audio.hpp>
#include <list>

#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>

class AudioHandler
{
    public:
        AudioHandler();
        ~AudioHandler(){};

        void playMusic(bool /*yes or no to music*/);

        void playSound(SoundEffect::ID /*sound id*/);

    private:
        SoundBufferHolder       _soundBufferHolder;
        sf::Music               _music;
        std::list<sf::Sound>    _sounds;
        
};

#endif // AUDIO_HANDLER_HPP