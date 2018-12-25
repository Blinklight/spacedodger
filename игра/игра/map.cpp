#include <SFML/Graphics.hpp>
#include "globals.h"
#include "map.h"
#include <fstream>
#include <string>


using namespace sf;



RenderWindow window(sf::VideoMode(1400, 700), "GAME");


Map::Map() {//конструктор класса

	image1.loadFromFile("images/map1.png");

	map.loadFromImage(image1);

	s_map.setTexture(map);

	Clock clock;

	window.clear(Color(33, 30, 30));

}

Map::~Map() {

}




void Map::drawing() {

	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(96, 0, 32, 32)); 
			if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
			if ((TileMap[i][j] == 'q')) s_map.setTextureRect(IntRect(0, 0, 32, 32));
			if ((TileMap[i][j] == 'w')) s_map.setTextureRect(IntRect(32, 0, 32, 32));
			if ((TileMap[i][j] == 'a')) s_map.setTextureRect(IntRect(0, 32, 32, 32));
			if ((TileMap[i][j] == 's')) s_map.setTextureRect(IntRect(32, 32, 32, 32));


			s_map.setPosition(j * 32, i * 32);

			window.draw(s_map);


		}
}

String TileMap[HEIGHT_MAP] = {

	"0000000000000000000000000000000000",
	"0                                0",
	"0                         P      0",
	"0                qw              0",
	"0                as       qw     0",
	"0                         as     0",
	"0     qw                    P    0",
	"0     as                         0",
	"0                     P          0",
	"0                                0",
	"0         qw                 L   0",
	"0         as                 L   0",
	"0                         qw     0",
	"0                         as     0",
	"0                                0",
	"0                qw              0",
	"0                as       P      0",
	"0                                0",
	"0                             L  0",
	"0000000000000000000000000000000000",
};