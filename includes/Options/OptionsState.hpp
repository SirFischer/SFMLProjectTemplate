#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"
#include "SoundPlayer.hpp"

class OptionsState : public State
{
private:
	mf::Button		*mSoundTestBtn;
	mf::Button		*mQuitBtn;

public:
	OptionsState(Window *tWindow);
	~OptionsState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

