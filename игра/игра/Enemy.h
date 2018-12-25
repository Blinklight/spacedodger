#pragma once
#pragma once 
#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "player.h" 

using namespace sf;

class Enemy {
public:
	FloatRect polozenie();
	float uskorenie();
	FloatRect rect;
	void checkCollisionWithMap();
	void drawing(float pX, float pY, Player & playerhp);
	float dx, dy;
	float x, y;
	int w, h;
	float speed;
	Image image;
	float time;
	Texture t;
	Sprite sprite;
	Sprite* ptr_sprite;
	float CurrentFrame;
	int EHp;
	bool life;
	int shoot = 0;
	Enemy();
	~Enemy();
	Clock clock;




};


class EasyE : public Enemy {
public:

	EasyE(int x, int y);

};

class HardE : public Enemy {
public:

	HardE(int x, int y);

};

class Bullet {
public:

	bool life;
	Clock clock;
	float time;
	FloatRect bullet_rect;
	Image im;
	Texture t;
	Sprite sprite;

	int direction;
	float dx, dy;
	Bullet(FloatRect rect, float loc_dx);
	void WithMap();
	Bullet();
	~Bullet();

	void WithPlayer(Player &p);
	void drawing();

};
