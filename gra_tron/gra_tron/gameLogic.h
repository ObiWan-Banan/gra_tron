#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<Windows.h>
#include"player.h"
#include"music.h"
#include"constants_definition.h"


void isCrashedWithRedTrail(int &winner,int* programState,player& redPlayer, player& greenPlayer, std::vector<sf::CircleShape>& redPlayerTrail, std::vector<sf::CircleShape>& greenPlayerTrail);
void isCrashedWithGreenTrail(int &winner,int* programState,player& redPlayer, player& greenPlayer, std::vector<sf::CircleShape>& greenPlayerTrail, std::vector<sf::CircleShape>& redPlayerTrail);
void resetAfterCrash(int* programState, music& music, bool* gameMusicSwitcher, std::vector<sf::CircleShape>& redPlayerTrail, std::vector<sf::CircleShape>& greenPlayerTrail);
void displayResult(sf::RenderWindow &window,int &winner);

void gameState(sf::RenderWindow &window, int* programState, player &redPlayer,player &greenPlayer,settings& settings, std::vector<sf::CircleShape> &redPlayerTrail, std::vector<sf::CircleShape> &greenPlayerTrail,sf::Sprite&gameBackground, music &music, bool *gameMusicSwitcher,bool *audioBlocker);
