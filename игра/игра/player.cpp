#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
#include "globals.h"
#include <iostream>
#include "map.h"
#include <list>





Player::Player()
{

}

Player::Player(String File, float X, float Y, float W, float H)
{

	File;
	w = W; h = H;
	imagee.loadFromFile("images/" + File);
	texturee.loadFromImage(imagee);

	sprite.setTexture(texturee);
	x = X; y = Y;
	sprite.setTextureRect(IntRect(0, 0, w, h));  
	sprite.setOrigin(w / 2, h / 2);
	hp = 10;
	dx = 0;
	dy = 0;
	ShootTimer = 20;
	speed = 0;
	dir = 0;
	hpbar.setFillColor(Color::Red);
	hpbar.setPosition(128, 10.f);
	hpbar.setSize(Vector2f((float)hp * 45.f, 10.f));

	

	CurrentFrame = 0;
	Clock clock;


}


PBullet::PBullet(FloatRect polozh, float uskor) {
	bullet_rect = polozh;
	life = true;
	im.loadFromFile("images/rocket1.png");
	sprite.setTextureRect(IntRect(0, 0, 20, 20));
	t.loadFromImage(im);
	sprite.setTexture(t);
	dx = 0.2;
}


void PBullet::drawing() {

	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 1000;

	sprite.setPosition(bullet_rect.left, bullet_rect.top);
	bullet_rect.left = bullet_rect.left + dx * time;

	WithMap();

	window.draw(sprite);

}
void PBullet::WithMap() {

	for (int i = (bullet_rect.top) / 32; i < (bullet_rect.top + 32) / 32; i++)
		for (int j = (bullet_rect.left) / 32; j < (bullet_rect.left + 32) / 32; j++)
		{
			if ((TileMap[i][j] == '0') || (TileMap[i][j] == 's') || (TileMap[i][j] == 'w'))
			{
				life = false;
			}
		}

}
PBullet::PBullet()
{

}
PBullet::~PBullet() {

}


FloatRect PBullet::polozenie() {
	
	
}
float PBullet::uskorenie() {
	return dx;
}

void Player::update(float time)
{


	switch (dir)
	{
	case 0: dx = speed; dy = 0;   break;
	case 1: dx = -speed; dy = 0;   break;
	case 2: dx = 0; dy = speed;   break;
	case 3: dx = 0; dy = -speed;   break;
	}

	x += dx * time;
	y += dy * time;

	if (ShootTimer < 15)
		ShootTimer++;

	speed = 0;
	sprite.setPosition(x, y); 
	InteractionWithMap();
}



void Player::draw_p() {
	
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 800;
	std::list<PBullet*> rock;
	std::list<PBullet*>::iterator pb;



	
	float coordinatePlayerX, coordinatePlayerY = 0;
	coordinatePlayerX = getplayercoordinateX();
	coordinatePlayerY = getplayercoordinateY();


	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
		dir = 1; speed = 0.1;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
		dir = 0; speed = 0.1;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
		dir = 3; speed = 0.1;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква ј
		dir = 2; speed = 0.1;
	}

	
	update(time);
	hpbar.setSize(Vector2f((float)hp * 45.f, 10.f));
	window.draw(sprite);

}


void Player::InteractionWithMap()
{

	for (int i = y / 32; i < ((y + h) / 32); i++)
		for (int j = x / 32; j < ((x + w) / 32); j++)
		{
			if ((TileMap[i][j] == '0') || (TileMap[i][j] == 's')) 
			{
				if (dy > 0)
				{
					y = i * 32 - h;
				}
				if (dy < 0)
				{
					y = i * 32 + 32;
				}
				if (dx > 0)
				{
					x = j * 32 - w;
				}
				if (dx < 0)
				{
					x = j * 32 + 32;
				}
			}
		}
}


float Player::getplayercoordinateX() {		
	return x;
}

float Player::getplayercoordinateY() {	 	
	return y;
}

void Player::bdamage()
{
	hp--;
}
void Player::edamage()
{
	hp-=2;
}

