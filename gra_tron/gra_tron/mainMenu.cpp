#include "mainMenu.h"

mainMenu::mainMenu(int Width, int Height)
{
	fontArial.loadFromFile("arial.ttf");
	fontRaiderCrusader.loadFromFile("raidercrusader.ttf");

	mainMenuTexture.loadFromFile("1.jpg");
	mainMenuTexture.setSmooth(true);
	mainMenuBackground.setTexture(mainMenuTexture);
	
	selectedButton = 0;

	heading.setFont(fontRaiderCrusader);
	heading.setString("TRON GAME");
	heading.setPosition(280, 50);
	heading.setCharacterSize(80);
	heading.setOutlineColor(sf::Color::Black);
	heading.setOutlineThickness(2);

	button[0].setFont(fontArial);
	button[0].setFillColor(sf::Color::Red);
	button[0].setString("Play");
	button[0].setPosition((Width / 2)-50, Height / 4);
	button[0].setCharacterSize(40);
	button[0].setOutlineThickness(1);
	button[0].setOutlineColor(sf::Color::Black);

	button[1].setFont(fontArial);
	button[1].setFillColor(sf::Color::Magenta);
	button[1].setString("Settings");
	button[1].setPosition((Width / 2) -75, (Height / 4 *2)-50);
	button[1].setCharacterSize(40);
	button[1].setOutlineThickness(1);
	button[1].setOutlineColor(sf::Color::Black);

	button[2].setFont(fontArial);
	button[2].setFillColor(sf::Color::Magenta);
	button[2].setString("Exit");
	button[2].setPosition((Width / 2) - 50, (Height / 4 * 3)-75);
	button[2].setCharacterSize(40);
	button[2].setOutlineThickness(1);
	button[2].setOutlineColor(sf::Color::Black);
	
}

void mainMenu::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(mainMenuBackground);
	window.draw(heading);
	for (int i = 0; i < NUMBER_OF_MAIN_MENU_BUTTONS; i++)
	{
		window.draw(button[i]);
	}
	window.display();
}

void mainMenu::moveUp()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (selectedButton - 1 >= 0)
		{
			button[selectedButton].setFillColor(sf::Color::Magenta);
			selectedButton--;
			button[selectedButton].setFillColor(sf::Color::Red);
		}
}

void mainMenu::moveDown()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (selectedButton + 1 < NUMBER_OF_MAIN_MENU_BUTTONS)
		{
			button[selectedButton].setFillColor(sf::Color::Magenta);
			selectedButton++;
			button[selectedButton].setFillColor(sf::Color::Red);
		}
}


void mainMenu::mainMenuState(sf::RenderWindow& window, int* programState,bool *mainMenuMusicSwitcher, music &music)
{
	if (*mainMenuMusicSwitcher == MUSIC_IS_NOT_PLAYING)
	{
		music.playMainMenuMusic();
		*mainMenuMusicSwitcher = MUSIC_IS_PLAYING;
	}
	
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		moveUp();
		moveDown();
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Enter)
			{
				if (selectedButton == 0)
				{
					*programState = GAME_PROGRAM_STATE;
					music.stopMainMenuMusic();
					*mainMenuMusicSwitcher = MUSIC_IS_NOT_PLAYING;
				}
				else if (selectedButton == 1)
				{
					*programState = SETTINGS_PROGRAM_STATE;
					selectedButton = 0;
					button[1].setFillColor(sf::Color::Magenta);
					button[0].setFillColor(sf::Color::Red);
				}
				else if (selectedButton == 2)
				{
					*programState = QUIT_PROGRAM_STATE;
				}
			}
		}
	}	
		draw(window);
}

