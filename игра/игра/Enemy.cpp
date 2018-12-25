#include "SFML/Graphics.hpp" 
#include <iostream> 
#include "map.h" 
#include "globals.h" 
#include "Enemy.h" 
#include "player.h" 

Enemy::Enemy()
{

}
Enemy::~Enemy()
{

}

FloatRect Enemy::polozenie() {
	return rect;
}
float Enemy::uskorenie() {
	return dx;
}

EasyE::EasyE(int x, int y) {
	t.loadFromFile("images/police1.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	rect = FloatRect(x * 32, y * 32, 0, 0);
	dx = -0.1;
	EHp = 1;
	life = true;
}


HardE::HardE(int x, int y)
{
	t.loadFromFile("images/dog.png");
	sprite.setTexture(t);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	rect = FloatRect(x * 32, y * 32, 0, 0);
	dx = -0.07;
	EHp = 2;
	life = true;
}
void Enemy::checkCollisionWithMap()
{

	for (int i = (rect.top) / 32; i < (rect.top + 32) / 32; i++)
		for (int j = (rect.left) / 32; j < (rect.left + 32) / 32; j++)
		{
			if ((TileMap[i][j] == '0') || (TileMap[i][j] == 's') || (TileMap[i][j] == 'w'))
			{
				life = false;
			}
		}
}

void Enemy::drawing(float pX, float pY, Player & playerhp)
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 800;


	sprite.setPosition(rect.left, rect.top);

	rect.left = rect.left + dx * time;
	checkCollisionWithMap();

	window.draw(sprite);

	if ((pY >= (rect.top - 15)) && (pY <= (rect.top + 32 + 15)) && (pX >= (rect.left - 15) && (pX <= (rect.left + 32 + 15)))) {
		playerhp.edamage();
		life = false;
	}
}
