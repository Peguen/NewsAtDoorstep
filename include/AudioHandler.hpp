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

        void playMusic(Music::ID /*which music to play*/, bool /*possible to disable*/);
        void toggleMusic();
        void reset();

        void playSound(SoundEffect::ID /*sound id*/);

    private:
        SoundBufferHolder       _soundBufferHolder;
        sf::Music               _readerMusic;
        sf::Music               _runnerMusic;
        std::list<sf::Sound>    _sounds;
        
};

#endif // AUDIO_HANDLER_HPP