#include "MenuState.hpp"

MenuState::MenuState(Window *tWindow)
{
	mWindow = tWindow;
}

MenuState::~MenuState()
{
}

void		MenuState::Init()
{
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->ShowCursor();
	
	/**
	 * INIT STATE AND GUI
	 **/

	mPlayBtn = mf::Button::Create(sf::Color::Green, sf::Color::Cyan);
	mPlayBtn->SetPositionPercentage(true)->SetPosition(45, 30);
	mPlayBtn->SetSize(150, 40);
	StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;
	mPlayBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::GAME;
		*active = false;
	});

	mOptionsBtn = mf::Button::Create(sf::Color::Blue, sf::Color::Yellow);
	mOptionsBtn->SetPositionPercentage(true)->SetPosition(45, 40);
	mOptionsBtn->SetSize(150, 40);
	mOptionsBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::OPTIONS;
		*active = false;
	});

		mQuitBtn = mf::Button::Create(sf::Color::Red, sf::Color::Yellow);
	mQuitBtn->SetPositionPercentage(true)->SetPosition(45, 50);
	mQuitBtn->SetSize(150, 40);
	mQuitBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::POP;
		*active = false;
	});

	mPlayBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mPlayBtn->SetTextColor(sf::Color::Black);
	mPlayBtn->SetTextPosition(sf::Vector2f(45, 0));
	mPlayBtn->SetText("Play!");

	mOptionsBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mOptionsBtn->SetTextColor(sf::Color::Black);
	mOptionsBtn->SetTextPosition(sf::Vector2f(22, 0));
	mOptionsBtn->SetText("Options");

	mQuitBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mQuitBtn->SetTextColor(sf::Color::Black);
	mQuitBtn->SetTextPosition(sf::Vector2f(48, 0));
	mQuitBtn->SetText("Quit");
	
	mf::GUI::AddWidget(mPlayBtn);
	mf::GUI::AddWidget(mOptionsBtn);
	mf::GUI::AddWidget(mQuitBtn);
}


void		MenuState::HandleEvents()
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

void		MenuState::Update()
{
}

void		MenuState::Render()
{
	mWindow->Clear(sf::Color::Black);
	mf::GUI::Render();
	mWindow->Render();
}