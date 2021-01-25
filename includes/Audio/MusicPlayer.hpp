#pragma once

#include <map>
#include "Music.hpp"
#include "SFML/Audio.hpp"

class MusicPlayer : sf::NonCopyable
{
private:
    sf::Music							mMusic;
    std::map<music::eID, std::string>	mFilenames;
    float								mVolume;
public:
    MusicPlayer(/* args */);
    ~MusicPlayer();

    void    Play(music::eID theme);
    void    Stop();

    void    SetPaused(bool tpaused);
    void    SetVolume(float tvolume);
};
