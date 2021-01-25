#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer()
: mMusic()
, mFilenames()
, mVolume(3.f)
{
	/*
	Set the music that you want to use here by for example typing:
	mFilenames[Music::GameTheme] = "assets/Music/Gamestate.wav";
	*/
}

MusicPlayer::~MusicPlayer()
{
}

void    MusicPlayer::Play(eMusic theme)
{
    std::string filename = mFilenames[theme];

    if (!mMusic.openFromFile(filename))
        throw std::runtime_error("Music " + filename + "could no be loaded.");
    mMusic.setVolume(mVolume);
    mMusic.setLoop(true);
    mMusic.play();
}

void    MusicPlayer::Stop()
{
    mMusic.stop();
}

void    MusicPlayer::SetPaused(bool paused)
{
    if (paused)
        mMusic.pause();
    else
        mMusic.play();
}