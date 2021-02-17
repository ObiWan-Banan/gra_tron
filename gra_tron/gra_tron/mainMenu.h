#pragma once
#include <SFML/Graphics.hpp>
#include"constants_definition.h"
#include"music.h"

class mainMenu
{

	int selectedButton;
	sf::Font fontArial;
	sf::Font fontRaiderCrusader;
	sf::Text button[NUMBER_OF_MAIN_MENU_BUTTONS];
	sf::Text heading;
	sf::Texture mainMenuTexture;
	sf::Sprite mainMenuBackground;
public:
	mainMenu(int Width, int Height);
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void mainMenuState(sf::RenderWindow& window, int* programState, bool *mainMenuMusicSwitcher,music &music);
};

