#include "AudioHandler.hpp"

AudioHandler::AudioHandler()
{
    _soundBufferHolder.load(SoundEffect::ID::Hit, "./resources/sounds/target_hit.ogg");
    _soundBufferHolder.load(SoundEffect::ID::Fail, "./resources/sounds/target_miss.ogg");
    _soundBufferHolder.load(SoundEffect::ID::Throw, "./resources/sounds/throw.ogg");
    _soundBufferHolder.load(SoundEffect::ID::Oy, "./resources/sounds/oy.ogg");
    
    _music.openFromFile("./resources/music/lu_da_53_music.ogg");
    _music.setLoop(true);
    _music.setVolume(20.f);
}

void AudioHandler::playMusic(bool enable)
{
    if (enable)
        _music.play();
    else
        _music.pause();
}

void AudioHandler::playSound(SoundEffect::ID soundID)
{
    _sounds.push_back(sf::Sound());
    sf::Sound& sound = _sounds.back();
    
    sound.setBuffer(_soundBufferHolder.get(soundID));
    // sound.setVolume(50.f);
    sound.play();
}
