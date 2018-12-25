#pragma once
#include "globals.h" // теперь всё работает
#include <SFML/Graphics.hpp>
using namespace sf;


using namespace sf;

class Player {
private:
	float x, y;

public:
	float w, h, dx, dy;
	Player();
	Player(String File, float X, float Y, float W, float H);
	int dir;
	Image imagee;
	Texture texturee;
	Sprite sprite;
	
	void update(float time);
	void InteractionWithMap();
	float speed;
	Clock clock;
	float time;
	int hp;
	int ShootTimer;
	void draw_p();
	float CurrentFrame;
	float coordinatePlayerX, coordinatePlayerY;
	float getplayercoordinateY();
	float getplayercoordinateX();
	void bdamage();
	void edamage();
	RectangleShape hpbar;
	


};


class PBullet {
public:
	FloatRect rect;
	bool life;
	Clock clock;
	float time;
	FloatRect bullet_rect;
	Image im;
	Texture t;
	Sprite sprite;
	int direction;
	float dx, dy;
	PBullet(FloatRect rect, float loc_dx);
	void WithMap();
	PBullet();
	~PBullet();
	FloatRect polozenie();
	float uskorenie();

	void WithEnemy();
	void drawing();

};