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

void    MusicPlayer::Play(eMusic tTheme)
{
    std::string filename = mFilenames[tTheme];

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

void    MusicPlayer::SetPaused(bool tPaused)
{
    if (tPaused)
        mMusic.pause();
    else
        mMusic.play();
}