#include "music.h"

music::music()
{
	mainMenuMusic.openFromFile("savfk-nebula.wav");
	gameMusic.openFromFile("punch-deck-feel-the-pulse.wav");
}

void music::playMainMenuMusic()
{
	mainMenuMusic.play();
	mainMenuMusic.setLoop(true);
}

void music::playGameMusic()
{
	gameMusic.play();
	gameMusic.setLoop(true);
}

void music::stopMainMenuMusic()
{
	mainMenuMusic.stop();
}

void music::stopGameMusic()
{
	gameMusic.stop();
}

void music::pauseMainMenuMusic()
{
	mainMenuMusic.pause();
}

int music::getMainMenuMusicStatus()
{
	return mainMenuMusic.getStatus();
}

