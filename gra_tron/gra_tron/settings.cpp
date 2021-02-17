#include "settings.h"

settings::settings()
{
	Width = 1024;
	Height = 768;
	circleRadius = 2;
	playerSpeed = 1.5;
	selectedButton = 0;
	selectedAudioButton = 0;
	selectedGameSpeedButton = 0;

	fontArial.loadFromFile("arial.ttf");
	fontRaiderCrusader.loadFromFile("raidercrusader.ttf");

	mainMenuTexture.loadFromFile("1.jpg");
	mainMenuTexture.setSmooth(true);
	mainMenuBackground.setTexture(mainMenuTexture);

	heading.setFont(fontRaiderCrusader);
	heading.setString("TRON GAME");
	heading.setPosition(280, 50);
	heading.setCharacterSize(80);
	heading.setOutlineColor(sf::Color::Black);
	heading.setOutlineThickness(2);

	button[0].setFont(fontArial);
	button[0].setFillColor(sf::Color::Red);
	button[0].setString("Music");
	button[0].setPosition((Width / 2) - 50, Height / 4);
	button[0].setCharacterSize(40);
	button[0].setOutlineThickness(1);
	button[0].setOutlineColor(sf::Color::Black);

	button[1].setFont(fontArial);
	button[1].setFillColor(sf::Color::Magenta);
	button[1].setString("Game Speed");
	button[1].setPosition((Width / 2)-100, (Height / 4 * 2) - 50);
	button[1].setCharacterSize(40);
	button[1].setOutlineThickness(1);
	button[1].setOutlineColor(sf::Color::Black);

	button[2].setFont(fontArial);
	button[2].setFillColor(sf::Color::Magenta);
	button[2].setString("Return");
	button[2].setPosition((Width / 2) - 60, (Height / 4 * 3) - 75);
	button[2].setCharacterSize(40);
	button[2].setOutlineThickness(1);
	button[2].setOutlineColor(sf::Color::Black);

	button[3].setFont(fontArial);
	button[3].setFillColor(sf::Color::Red);
	button[3].setString("ON");
	button[3].setPosition((Width / 2) + 75, Height / 4);
	button[3].setCharacterSize(40);
	button[3].setOutlineThickness(1);
	button[3].setOutlineColor(sf::Color::Black);

	button[4].setFont(fontArial);
	button[4].setFillColor(sf::Color::Red);
	button[4].setString("OFF");
	button[4].setPosition((Width / 2) +75, Height / 4);
	button[4].setCharacterSize(40);
	button[4].setOutlineThickness(1);
	button[4].setOutlineColor(sf::Color::Black);


	button[5].setFont(fontArial);
	button[5].setFillColor(sf::Color::Magenta);
	button[5].setString("Slow");
	button[5].setPosition((Width / 2)+160, (Height / 4 * 2) - 50);
	button[5].setCharacterSize(40);
	button[5].setOutlineThickness(1);
	button[5].setOutlineColor(sf::Color::Black);

	button[6].setFont(fontArial);
	button[6].setFillColor(sf::Color::Magenta);
	button[6].setString("Fast");
	button[6].setPosition((Width / 2)+160, (Height / 4 * 2) - 50);
	button[6].setCharacterSize(40);
	button[6].setOutlineThickness(1);
	button[6].setOutlineColor(sf::Color::Black);

	button[7].setFont(fontArial);
	button[7].setFillColor(sf::Color::Magenta);
	button[7].setString("Too Fast");
	button[7].setPosition((Width / 2)+160, (Height / 4 * 2) - 50);
	button[7].setCharacterSize(40);
	button[7].setOutlineThickness(1);
	button[7].setOutlineColor(sf::Color::Black);


}

void settings::moveUp()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (selectedButton - 1 >= 0)
		{
			if(selectedButton==1)
			{
				button[5].setFillColor(sf::Color::Magenta);
				button[6].setFillColor(sf::Color::Magenta);
				button[7].setFillColor(sf::Color::Magenta);
			}
			button[selectedButton].setFillColor(sf::Color::Magenta);
			selectedButton--;
			button[selectedButton].setFillColor(sf::Color::Red);
			if (selectedButton == 0)
			{
				button[3].setFillColor(sf::Color::Red);
				button[4].setFillColor(sf::Color::Red);
			}
			else if (selectedButton == 1)
			{
				button[5].setFillColor(sf::Color::Red);
				button[6].setFillColor(sf::Color::Red);
				button[7].setFillColor(sf::Color::Red);
			}
		}
}

void settings::moveDown()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (selectedButton + 1 < NUMBER_OF_MAIN_MENU_BUTTONS)
		{
			if (selectedButton == 0)
			{
				button[3].setFillColor(sf::Color::Magenta);
				button[4].setFillColor(sf::Color::Magenta);
			}
			else if (selectedButton == 1)
			{
				button[5].setFillColor(sf::Color::Magenta);
				button[6].setFillColor(sf::Color::Magenta);
				button[7].setFillColor(sf::Color::Magenta);
			}
			button[selectedButton].setFillColor(sf::Color::Magenta);
			selectedButton++;
			button[selectedButton].setFillColor(sf::Color::Red);
			if (selectedButton == 1)
			{
				button[5].setFillColor(sf::Color::Red);
				button[6].setFillColor(sf::Color::Red);
				button[7].setFillColor(sf::Color::Red);
			}
		}
}

void settings::horizontalSwitcher()
{
	
	if (selectedButton == 0)
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (selectedAudioButton == 0)
			{
				selectedAudioButton = 1;
			}
			else
			{
				selectedAudioButton = 0;
			}
		}
	}
	else if (selectedButton == 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (selectedGameSpeedButton == 0) selectedGameSpeedButton = 1;
			else if (selectedGameSpeedButton == 1) selectedGameSpeedButton = 2;
			else if (selectedGameSpeedButton == 2) selectedGameSpeedButton = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (selectedGameSpeedButton == 0) selectedGameSpeedButton = 2;
			else if (selectedGameSpeedButton == 1) selectedGameSpeedButton = 0;
			else if (selectedGameSpeedButton == 2) selectedGameSpeedButton = 1;
		}
	}
}

void settings::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(mainMenuBackground);
	window.draw(heading);
	for (int i = 0; i < NUMBER_OF_MAIN_MENU_BUTTONS; i++)
	{
		window.draw(button[i]);
	}
	if (selectedAudioButton == 0) window.draw(button[3]);
	else if (selectedAudioButton == 1) window.draw(button[4]);
	if (selectedGameSpeedButton == 0) window.draw(button[5]);
	else if (selectedGameSpeedButton == 1) window.draw(button[6]);
	else if (selectedGameSpeedButton == 2) window.draw(button[7]);
	window.display();
}

void settings::audioSwitcher(music& music, bool* audioblocker)
{
	if (selectedButton == 0)
	{
		if (selectedAudioButton == 0)
		{
			if (*audioblocker != AUDIO_ON) *audioblocker = AUDIO_ON;
			if (music.getMainMenuMusicStatus() != 2)
			{
				music.playMainMenuMusic();
			}
		}
		else if (selectedAudioButton == 1)
		{
			if (*audioblocker != AUDIO_OFF)*audioblocker = AUDIO_OFF;
			if (music.getMainMenuMusicStatus() != 0 || music.getMainMenuMusicStatus() != 1)
			{
				music.pauseMainMenuMusic();
			}
		}
	}
}

void settings::gameSpeedSwitcher(sf::RenderWindow& window)
{
	if (selectedButton == 1)
	{
		if (selectedGameSpeedButton == 0)
		{
			if (playerSpeed != 1.5)
			{
				playerSpeed = 1.5;
				window.setFramerateLimit(playerSpeed * 60);
			}
		}
		else if (selectedGameSpeedButton == 1)
		{
			if (playerSpeed != 2.5)
			{
				playerSpeed = 2.5;
				window.setFramerateLimit(playerSpeed * 60);
			}
		}
		else if (selectedGameSpeedButton == 2)
		{
			if (playerSpeed != 3.75)
			{
				playerSpeed = 3.75;
				window.setFramerateLimit(playerSpeed * 60);
			}
		}
	}
}

int settings::getWidth()
{
	return this->Width;
}

int settings::getHeight()
{
	return Height;
}

int settings::getCircleRadius()
{
	return circleRadius;
}

int settings::getPlayerSpeed()
{
	return playerSpeed;
}

void settings::settingsState(sf::RenderWindow& window, int* programState, bool* audioBlocker, music& music)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		moveUp();
		moveDown();
		horizontalSwitcher();
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code==sf::Keyboard::Enter)
			{
				if (selectedButton == 2)
				{
					*programState = MAIN_MENU_PROGRAM_STATE;
					selectedButton = 0;
					button[2].setFillColor(sf::Color::Magenta);
					button[0].setFillColor(sf::Color::Red);
					button[3].setFillColor(sf::Color::Red);
					button[4].setFillColor(sf::Color::Red);
				}
			}
		}
	}
	audioSwitcher(music, audioBlocker);
	gameSpeedSwitcher(window);
	draw(window);
}
