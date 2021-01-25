#include "SoundPlayer.hpp"

std::map<soundeffect::eID, std::string>		SoundPlayer::mSoundNames = std::map<soundeffect::eID, std::string>();
std::map<soundeffect::eID, sf::Sound>		SoundPlayer::mSoundList = std::map<soundeffect::eID, sf::Sound>();
float										SoundPlayer::mVolume = 	50.f;

SoundPlayer::SoundPlayer(/* args */)
{
}

SoundPlayer::~SoundPlayer()
{
}

void	SoundPlayer::Init()
{
    SoundPlayer::mSoundNames[soundeffect::eID::SOUNDTEST] = "assets/fonts/SoundEffects/click.ogg";
}

void    SoundPlayer::Play(soundeffect::eID effect)
{
	if (mSoundList[effect].getStatus() == sf::Sound::Playing)
		return ;
    std::string SoundName = mSoundNames[effect];

    mSoundList[effect].setBuffer(*ResourceManager::LoadSoundBuffer(SoundName));
    mSoundList[effect].setLoop(false);
    mSoundList[effect].play();
}

void    SoundPlayer::StopSound(soundeffect::eID effect)
{
    mSoundList[effect].stop();
}

void	SoundPlayer::SetPitch(soundeffect::eID effect, float tPitch)
{
	mSoundList[effect].setPitch(tPitch);
}

void	SoundPlayer::SetVolume(soundeffect::eID effect, float tVolume)
{
	mSoundList[effect].setVolume(tVolume * mVolume);
}



void    SoundPlayer::StopSound()
{
	for (auto &sound : mSoundList)
		sound.second.stop();
}