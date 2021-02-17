#include"gameLogic.h"



void isCrashedWithRedTrail(int &winner,int* programState,player& redPlayer, player& greenPlayer, std::vector<sf::CircleShape>& redPlayerTrail, std::vector<sf::CircleShape>& greenPlayerTrail)
{
	for (int i = 0; i < redPlayerTrail.size(); i++)
	{
		if (redPlayer.getX() == redPlayerTrail[i].getPosition().x && redPlayer.getY() == redPlayerTrail[i].getPosition().y)
		{
			winner = GREEN_WINS;
			
		}
		if (greenPlayer.getX() == redPlayerTrail[i].getPosition().x && greenPlayer.getY() == redPlayerTrail[i].getPosition().y)
		{
			winner = RED_WINS;
		}
	}
}

void isCrashedWithGreenTrail(int&winner,int* programState,player& redPlayer, player& greenPlayer, std::vector<sf::CircleShape>& greenPlayerTrail, std::vector<sf::CircleShape>& redPlayerTrail)
{
	for (int i = 0; i < greenPlayerTrail.size(); i++)
	{
		if (redPlayer.getX() == greenPlayerTrail[i].getPosition().x && redPlayer.getY() == greenPlayerTrail[i].getPosition().y)
		{
			winner = GREEN_WINS;
		}

		if (greenPlayer.getX() == greenPlayerTrail[i].getPosition().x && greenPlayer.getY() == greenPlayerTrail[i].getPosition().y)
		{
			winner = RED_WINS;
		}
	}
}

void resetAfterCrash(int* programState, music& music, bool* gameMusicSwitcher, std::vector<sf::CircleShape>& redPlayerTrail, std::vector<sf::CircleShape>& greenPlayerTrail)
{
	greenPlayerTrail.clear();
	redPlayerTrail.clear();
	music.stopGameMusic();
	*gameMusicSwitcher = MUSIC_IS_NOT_PLAYING;
	*programState = MAIN_MENU_PROGRAM_STATE;
}

void displayResult(sf::RenderWindow& window, int& winner)
{
	sf::Text heading;
	sf::Font font;
	font.loadFromFile("raidercrusader.ttf");
	heading.setFont(font);
	heading.setPosition(260, 50);
	heading.setCharacterSize(60);
	heading.setOutlineColor(sf::Color::Black);
	heading.setOutlineThickness(2);
	if (winner == RED_WINS)
	{
		heading.setString("RED PLAYER WINS");
		heading.setFillColor(sf::Color::Red);
		window.draw(heading);
	}
	else if (winner == GREEN_WINS)
	{
		heading.setString("GREEN PLAYER WINS");
		heading.setFillColor(sf::Color::Green);
		window.draw(heading);
	}
	else if (winner == DRAW) 
	{
		heading.setString("DRAW");
		window.draw(heading);
	}
}



void gameState(sf::RenderWindow& window, int* programState, player &redPlayer, player &greenPlayer, settings &settings, std::vector<sf::CircleShape> &redPlayerTrail, std::vector<sf::CircleShape> &greenPlayerTrail, sf::Sprite& gameBackground,music &music,bool* gameMusicSwitcher, bool* audioBlocker)
{

	int winner = 0;
	if (*audioBlocker == AUDIO_ON)
	{
		if (*gameMusicSwitcher == MUSIC_IS_NOT_PLAYING)
		{
			music.playGameMusic();
			*gameMusicSwitcher = MUSIC_IS_PLAYING;
		}
	}
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (redPlayer.getDirection() != 1)
			redPlayer.changeDirection(0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (redPlayer.getDirection() != 0)
			redPlayer.changeDirection(1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (redPlayer.getDirection() != 3)
			redPlayer.changeDirection(2);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (redPlayer.getDirection() != 2)
			redPlayer.changeDirection(3);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (greenPlayer.getDirection() != 1)
			greenPlayer.changeDirection(0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (greenPlayer.getDirection() != 0)
			greenPlayer.changeDirection(1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if (greenPlayer.getDirection() != 3)
			greenPlayer.changeDirection(2);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (greenPlayer.getDirection() != 2)
			greenPlayer.changeDirection(3);

	redPlayer.playerMove(settings);
	greenPlayer.playerMove(settings);
	if (greenPlayer.getX() - 4 < redPlayer.getX() && redPlayer.getX() < greenPlayer.getX() + 4 && greenPlayer.getY() - 4 < redPlayer.getY() && redPlayer.getY() < greenPlayer.getY() + 4)
	{
		winner = DRAW;
	}
	isCrashedWithRedTrail(winner, programState, redPlayer, greenPlayer, redPlayerTrail, greenPlayerTrail);
	
	isCrashedWithGreenTrail(winner, programState, redPlayer, greenPlayer, greenPlayerTrail, redPlayerTrail);
	

	sf::CircleShape redC(settings.getCircleRadius());
	redC.setPosition(redPlayer.getX(), redPlayer.getY());
	redC.setFillColor(sf::Color::Red);
	redPlayerTrail.push_back(redC);



	sf::CircleShape greenC(settings.getCircleRadius());
	greenC.setPosition(greenPlayer.getX(), greenPlayer.getY());
	greenC.setFillColor(sf::Color::Green);
	greenPlayerTrail.push_back(greenC);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		*programState = MAIN_MENU_PROGRAM_STATE;
		resetAfterCrash(programState, music, gameMusicSwitcher, redPlayerTrail, greenPlayerTrail);
	}

	window.clear();
	window.draw(gameBackground);
	for (int i = 0; i < redPlayerTrail.size(); i++)
	{
		window.draw(redPlayerTrail[i]);
	}
	for (int i = 0; i < greenPlayerTrail.size(); i++)
	{
		window.draw(greenPlayerTrail[i]);
	}
	if (winner != 0) displayResult(window, winner);
	window.display();
	if (winner != 0)
	{
		Sleep(2500);
		resetAfterCrash(programState, music, gameMusicSwitcher, redPlayerTrail, greenPlayerTrail);
	}
}
