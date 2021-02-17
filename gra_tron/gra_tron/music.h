#pragma once
#include <SFML/Audio.hpp>
class music
{
	sf::Music mainMenuMusic;
	sf::Music gameMusic;
public:
	music();
	void playMainMenuMusic();
	void playGameMusic();
	void stopMainMenuMusic();
	void stopGameMusic();
	void pauseMainMenuMusic();
	int getMainMenuMusicStatus();
};

