#pragma once
#include "player.h"



player::player(sf::Color color, settings &settings)
{
	x = rand() % settings.getWidth();
	y = rand() % settings.getHeight();
	this->playerColor = color;
	direction = rand() % 4;
}

void player::playerMove(settings &settings)
{
	//direction=0 ruch w dó³
	//direction=1 ruch w góre
	//direction=2 ruch w lewo
	//direction=3 ruch w prawo
	if (direction == 0)
	{
		this->y += 1;
	}
	else if (direction == 1)
	{
		this->y -= 1;
	}
	else if (direction == 2)
	{
		this->x -=1;
	}
	else if (direction == 3)
	{
		this->x += 1;
	}
	//gracz napotyka krawedz okna
	if (this->y >= settings.getHeight())
	{
		this->y = 1;
	}
	if (this->y <= 0)
	{
		this->y = settings.getHeight() - 1;
	}
	if (this->x >= settings.getWidth())
	{
		this->x = 1;
	}
	if (this->x <= 0)
	{
		this->x = settings.getWidth();
	}
}

int player::getX()
{
	return this->x;
}

int player::getY()
{
	return y;
}

int player::getDirection()
{
	return direction;
}

void player::changeDirection(int newDirection)
{
	this->direction = newDirection;
}

