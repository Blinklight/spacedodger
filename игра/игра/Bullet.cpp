#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "map.h" 
#include "globals.h" 
#include "Enemy.h" 
#include "player.h" 
#pragma once



Bullet::Bullet(FloatRect polozh, float uskor) {
	bullet_rect = polozh;
	life = true;
	im.loadFromFile("images/rocket.png");
	sprite.setTextureRect(IntRect(0, 0, 20, 20));
	t.loadFromImage(im);
	sprite.setTexture(t);
	dx = -0.2;
}

	void Bullet::drawing() {

		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 1000;

		sprite.setPosition(bullet_rect.left, bullet_rect.top);
		bullet_rect.left = bullet_rect.left + dx * time;

		WithMap();

		window.draw(sprite);
	}
	
	void Bullet::WithMap() {

		for (int i = (bullet_rect.top) / 32; i < (bullet_rect.top + 32) / 32; i++)
			for (int j = (bullet_rect.left) / 32; j < (bullet_rect.left + 32) / 32; j++)
			{
				if ((TileMap[i][j] == '0') || (TileMap[i][j] == 's') || (TileMap[i][j] == 'w'))
				{
					life = false;
				}
			}

	}
	Bullet::Bullet()
	{

	}
	Bullet::~Bullet() {

	}

	void Bullet::WithPlayer(Player &p) {
		if ((((p.getplayercoordinateX()) >= ((bullet_rect.left))) && ((p.getplayercoordinateX()) <= ((bullet_rect.left) + 10))) && (((p.getplayercoordinateY()) >= (bullet_rect.top)) && ((p.getplayercoordinateY()) <= (bullet_rect.top) + 32))) {
			life = false;
			p.bdamage();
			return;
		}
	}
	
