#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"settings.h"
class player
{

	int x;
	int y;
	int direction;
	sf::Color playerColor;
public:
	player(sf::Color color, settings &settings);
	void playerMove(settings &settings);
	int getX();
	int getY();
	int getDirection();
	void changeDirection(int newDirection);
};

