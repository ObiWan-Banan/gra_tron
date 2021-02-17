	#pragma once
#include <SFML/Graphics.hpp>
#include"constants_definition.h"
#include"music.h"

class settings
{
	 int Width;
	 int Height;
	 int circleRadius;
	 float playerSpeed;
	 int selectedButton;
	 int selectedAudioButton;
	 int selectedGameSpeedButton;
	 sf::Text button[NUMBER_OF_SETTINGS_BUTTONS];
	 sf::Texture mainMenuTexture;
	 sf::Text heading;
	 sf::Sprite mainMenuBackground;
	 sf::Font fontArial;
	 sf::Font fontRaiderCrusader;
	 
public:
	settings();
	void moveUp();
	void moveDown();
	void horizontalSwitcher();
	void draw(sf::RenderWindow& window);
	void audioSwitcher(music& music, bool* audioblocker);
	void gameSpeedSwitcher(sf::RenderWindow& window);
	int getWidth();
	int getHeight();
	int getCircleRadius();
	int getPlayerSpeed();
	void settingsState(sf::RenderWindow& window, int* programState,bool* audioBlocker, music& music);
};