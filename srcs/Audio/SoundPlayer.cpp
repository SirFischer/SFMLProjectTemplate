#include "SoundPlayer.hpp"

std::map<eSound, std::string>	SoundPlayer::mSoundNames = std::map<eSound, std::string>();
std::map<eSound, sf::Sound>		SoundPlayer::mSoundList = std::map<eSound, sf::Sound>();
float							SoundPlayer::mVolume = 	50.f;

SoundPlayer::SoundPlayer(/* args */)
{
}

SoundPlayer::~SoundPlayer()
{
}

void	SoundPlayer::Init()
{
    SoundPlayer::mSoundNames[eSound::SOUNDTEST] = "assets/fonts/SoundEffects/click.ogg";
}

void    SoundPlayer::Play(eSound tEffect)
{
	if (mSoundList[tEffect].getStatus() == sf::Sound::Playing)
		return ;
    std::string SoundName = mSoundNames[tEffect];

    mSoundList[tEffect].setBuffer(*ResourceManager::LoadSoundBuffer(SoundName));
    mSoundList[tEffect].setLoop(false);
    mSoundList[tEffect].play();
}

void    SoundPlayer::StopSound(eSound tEffect)
{
    mSoundList[tEffect].stop();
}

void	SoundPlayer::SetPitch(eSound tEffect, float tPitch)
{
	mSoundList[tEffect].setPitch(tPitch);
}

void	SoundPlayer::SetVolume(eSound tEffect, float tVolume)
{
	mSoundList[tEffect].setVolume(tVolume * mVolume);
}



void    SoundPlayer::StopSound()
{
	for (auto &sound : mSoundList)
		sound.second.stop();
}