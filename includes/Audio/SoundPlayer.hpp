#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include "Sound.hpp"
#include "ResourceManager.hpp"

class SoundPlayer : sf::NonCopyable
{
private:
    static std::map<soundeffect::eID, std::string>		mSoundNames;
	static std::map<soundeffect::eID, sf::Sound>		mSoundList;

    static float										mVolume;
	
	SoundPlayer(/* args */);
public:
    ~SoundPlayer();

	static void											Init();

    static void											Play(soundeffect::eID effect);

    static void											StopSound(soundeffect::eID effect);
    static void											StopSound();

	static void											SetPitch(soundeffect::eID effect, float tPitch);
	static void											SetVolume(soundeffect::eID effect, float tVolume);

    static sf::Sound									GetSound(soundeffect::eID tEffect){return (mSoundList[tEffect]);}

};