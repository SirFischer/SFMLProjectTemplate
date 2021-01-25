#include "SoundPlayer.hpp"

std::map<SoundEffect::eID, std::string>		SoundPlayer::mSoundNames = std::map<SoundEffect::eID, std::string>();
std::map<SoundEffect::eID, sf::Sound>		SoundPlayer::mSoundList = std::map<SoundEffect::eID, sf::Sound>();
float										SoundPlayer::mVolume = 50.f;



SoundPlayer::SoundPlayer(/* args */)
{
}

SoundPlayer::~SoundPlayer()
{
}

void	SoundPlayer::Init()
{
    SoundPlayer::mSoundNames[SoundEffect::eID::SOUNDTEST] = "assets/fonts/SoundEffects/click.ogg";

}

void    SoundPlayer::Play(SoundEffect::eID effect)
{
	std::cout<<mSoundNames[SoundEffect::eID::SOUNDTEST]<<'\n';
	if (mSoundList[effect].getStatus() == sf::Sound::Playing)
		return ;
    std::string SoundName = mSoundNames[effect];

    mSoundList[effect].setBuffer(*ResourceManager::LoadSoundBuffer(SoundName));
    mSoundList[effect].setLoop(false);
    mSoundList[effect].play();
}

void    SoundPlayer::StopSound(SoundEffect::eID effect)
{
    mSoundList[effect].stop();
}

void	SoundPlayer::SetPitch(SoundEffect::eID effect, float tPitch)
{
	mSoundList[effect].setPitch(tPitch);
}

void	SoundPlayer::SetVolume(SoundEffect::eID effect, float tVolume)
{
	mSoundList[effect].setVolume(tVolume * mVolume);
}



void    SoundPlayer::StopSound()
{
	for (auto &sound : mSoundList)
		sound.second.stop();
}