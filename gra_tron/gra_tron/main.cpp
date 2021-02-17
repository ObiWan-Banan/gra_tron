#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"player.h"
#include"settings.h"
#include"mainMenu.h"
#include"gameLogic.h"
#include"music.h"


int main()
{
	srand(time(0));
	settings settings;
	mainMenu mainMenu(settings.getWidth(), settings.getHeight());
	music music;
	
	sf::RenderWindow window(sf::VideoMode(settings.getWidth(), settings.getHeight()), "Tron Game");
	window.setFramerateLimit(settings.getPlayerSpeed()*60);
	window.setActive(true);

	sf::Texture texture;
	texture.loadFromFile("2.jpg");
	texture.setSmooth(true);
	sf::Sprite gameBackground;
	gameBackground.setTexture(texture);

	player redPlayer(sf::Color::Red,settings);
	player greenPlayer(sf::Color::Green,settings);
	
	std::vector<sf::CircleShape> redPlayerTrail;
	std::vector<sf::CircleShape> greenPlayerTrail;
	
	bool mainMenuMusicSwitcher = MUSIC_IS_NOT_PLAYING;
	bool gameMusicSwitcher = MUSIC_IS_NOT_PLAYING;
	bool audioBlocker = AUDIO_ON;
	int programState = MAIN_MENU_PROGRAM_STATE;
	while (window.isOpen())
	{
		switch (programState)
		{
		case MAIN_MENU_PROGRAM_STATE:
		{
			mainMenu.mainMenuState(window,&programState,&mainMenuMusicSwitcher,music);
			break;
		}
		case GAME_PROGRAM_STATE:
		{
			gameState(window, &programState, redPlayer, greenPlayer, settings, redPlayerTrail, greenPlayerTrail,gameBackground,music,&gameMusicSwitcher,&audioBlocker);
			break;
		}
		case SETTINGS_PROGRAM_STATE:
		{
			settings.settingsState(window, &programState, &audioBlocker, music);
			break;
		}
		case QUIT_PROGRAM_STATE:
		{
			return 0;
			break;
		}
		}

	}

	return 0;
}