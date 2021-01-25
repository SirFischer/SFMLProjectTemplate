#pragma once

#include <map>
#include "Music.hpp"
#include "SFML/Audio.hpp"

class MusicPlayer : sf::NonCopyable
{
private:
    sf::Music							mMusic;
    std::map<eMusic, std::string>		mFilenames;
    float								mVolume;
public:
    MusicPlayer(/* args */);
    ~MusicPlayer();

    void    Play(eMusic tTheme);
    void    Stop();

    void    SetPaused(bool tPaused);
    void    SetVolume(float tVolume);
};
