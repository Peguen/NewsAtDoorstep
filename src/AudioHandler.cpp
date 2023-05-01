#include "AudioHandler.hpp"

AudioHandler::AudioHandler()
{
    _soundBufferHolder.load(SoundEffect::ID::Hit, "./resources/sounds/target_hit.ogg");
    _soundBufferHolder.load(SoundEffect::ID::Fail, "./resources/sounds/target_miss.ogg");
    _soundBufferHolder.load(SoundEffect::ID::Throw, "./resources/sounds/throw.ogg");
    _soundBufferHolder.load(SoundEffect::ID::Oy, "./resources/sounds/oy.ogg");
    
    _runnerMusic.openFromFile("./resources/music/lu_da_53_music_state_running.ogg");
    _runnerMusic.setLoop(true);
    _runnerMusic.setVolume(20.f);

    _readerMusic.openFromFile("./resources/music/lu_da_53_music_state_reading.ogg");
    _readerMusic.setLoop(true);
    _readerMusic.setVolume(20.f);
}

void AudioHandler::playMusic(Music::ID musicID, bool enable)
{
    switch (musicID) 
    {
        case Music::ID::Reading:
        {
            if(enable)
                _readerMusic.play();
            else
                _readerMusic.stop();
            break;
        }
        case Music::ID::Running:
        {
            if(enable)
                _runnerMusic.play();
            else
                _runnerMusic.stop();
            break;
        }
    }
}

void AudioHandler::playSound(SoundEffect::ID soundID)
{
    _sounds.push_back(sf::Sound());
    sf::Sound& sound = _sounds.back();
    
    sound.setBuffer(_soundBufferHolder.get(soundID));
    // sound.setVolume(50.f);
    sound.play();
}

void AudioHandler::toggleMusic()
{
    // if both are stopped - no toggle
    if (_runnerMusic.getStatus() == sf::SoundSource::Status::Playing)
    {
        _runnerMusic.stop();
        _readerMusic.play();
    }
    else if (_readerMusic.getStatus() == sf::SoundSource::Status::Playing)
    {
        _readerMusic.stop();
        _runnerMusic.play();
    }
}
