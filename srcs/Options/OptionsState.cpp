#include "OptionsState.hpp"

OptionsState::OptionsState(Window *tWindow)
{
	mWindow = tWindow;
}

OptionsState::~OptionsState()
{
}

void		OptionsState::Init()
{
	mf::GUI::ClearWidgets();
	mWindow->ShowCursor();

	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;

	/**
	 * INIT STATE AND GUI
	 **/
	mSoundTestBtn = mf::Button::Create(sf::Color::Green, sf::Color::Cyan);
	mSoundTestBtn->SetPositionPercentage(true)->SetPosition(45, 40);
	mSoundTestBtn->SetSize(150, 40);
	mSoundTestBtn->SetClickEvent([&] {
		SoundPlayer::Init();
		SoundPlayer::Play(eSound::SOUNDTEST);
	});

	mSoundTestBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mSoundTestBtn->SetTextColor(sf::Color::Black);
	mSoundTestBtn->SetTextPosition(sf::Vector2f(10, 2));
	mSoundTestBtn->SetCharacterSize(25);
	mSoundTestBtn->SetText("Sound Test");

	mQuitBtn = mf::Button::Create(sf::Color::Red, sf::Color::Yellow);
	mQuitBtn->SetPositionPercentage(true)->SetPosition(45, 50);
	mQuitBtn->SetSize(150, 40);
	mQuitBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::POP;
		*active = false;
	});

	mQuitBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mQuitBtn->SetTextColor(sf::Color::Black);
	mQuitBtn->SetTextPosition(sf::Vector2f(45, 0));
	mQuitBtn->SetText("Back");


	mf::GUI::AddWidget(mQuitBtn);
	mf::GUI::AddWidget(mSoundTestBtn);
}

void		OptionsState::HandleEvents()
{
	sf::Event event;
	while (mWindow->HandleEvent(event))
	{
		mf::GUI::HandleEvent(event);
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		{
			mIsActive = false;
		}
	}
}

void		OptionsState::Update()
{
}

void		OptionsState::Render()
{
	mWindow->Clear(sf::Color::Black);
	mf::GUI::Render();
	mWindow->Render();
}