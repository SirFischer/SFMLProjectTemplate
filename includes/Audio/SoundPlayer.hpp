#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include "Sound.hpp"
#include "ResourceManager.hpp"

class SoundPlayer : sf::NonCopyable
{
private:
    static std::map<eSound, std::string>		mSoundNames;
	static std::map<eSound, sf::Sound>			mSoundList;

    static float								mVolume;
	
	SoundPlayer(/* args */);
public:
    ~SoundPlayer();

	static void											Init();

    static void											Play(eSound tEffect);

    static void											StopSound(eSound tEffect);
    static void											StopSound();

	static void											SetPitch(eSound tEffect, float tPitch);
	static void											SetVolume(eSound tEffect, float tVolume);

    static sf::Sound									GetSound(eSound tEffect){return (mSoundList[tEffect]);}

};