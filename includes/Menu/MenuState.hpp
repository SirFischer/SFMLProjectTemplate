#pragma once

#include "State.hpp"

class MenuState : public State
{
private:
	mf::Button		*mPlayBtn;
	mf::Button		*mQuitBtn;
	
public:
	MenuState(Window *tWindow);
	~MenuState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

