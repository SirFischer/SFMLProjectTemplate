#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include "Sound.hpp"
#include "ResourceManager.hpp"

class SoundPlayer : sf::NonCopyable
{
private:
    static std::map<SoundEffect::eID, std::string>			mSoundNames;
	static std::map<SoundEffect::eID, sf::Sound>			mSoundList;

    static float                                      	mVolume;
	
	SoundPlayer(/* args */);
public:
    ~SoundPlayer();

	static void											Init();

    static void            								Play(SoundEffect::eID effect);

    static void            								StopSound(SoundEffect::eID effect);
    static void            								StopSound();

	static void											SetPitch(SoundEffect::eID effect, float tPitch);
	static void											SetVolume(SoundEffect::eID effect, float tVolume);

    static sf::Sound       								GetSound(SoundEffect::eID tEffect){return (mSoundList[tEffect]);}

};