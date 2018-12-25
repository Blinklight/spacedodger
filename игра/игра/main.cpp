#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.h"
#include "globals.h"
#include "player.h"
#include "Enemy.h"
#include <list>




using namespace std;
using namespace sf;



int main()
{
	Map drawing;
	//Player draw_p;
	Player z("ss.png", 128, 128, 32, 32);
	Map m;
	//Player z;
	Clock clock;
	window.clear();
	Font font;
	font.loadFromFile("Dosis-Light.ttf");
	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(50);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(100.f, window.getSize().y / 2);
	gameOverText.setString("GAME OVER!");

	std::list<Enemy*> Vrag;
	std::list<Enemy*>::iterator ee;

	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bul;

	std::list<PBullet*> rock;
	std::list<PBullet*>::iterator pb;




	
	while (window.isOpen())
	{
		
			for (int i = 0; i < HEIGHT_MAP; i++) {
				for (int j = 0; j < WIDTH_MAP; j++) {

					if (TileMap[i][j] == 'L') {

						Vrag.push_back(new EasyE(j, i));

					}
					if (TileMap[i][j] == 'P') {

						Vrag.push_back(new HardE(j, i));

					}
					sf::Event event;
					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							window.close();
					}
					if (z.hp >= 0) {
					m.drawing();
					z.draw_p();

					for (ee = Vrag.begin(); ee != Vrag.end(); ee++) {
						if ((*ee)->life) {
							(*ee)->drawing(z.getplayercoordinateX(), z.getplayercoordinateY(), z);
							if ((*ee)->shoot > 200) {
								(*ee)->shoot = 0;
								FloatRect polozh = (*ee)->polozenie();
								float uskor = (*ee)->uskorenie();
								bullets.push_back(new Bullet(polozh, uskor));
							}
							(*ee)->shoot++;
						}

						else {
							delete((*ee));
							Vrag.remove(*ee);
							break;
						}
					}
					for (bul = bullets.begin(); bul != bullets.end(); bul++) {
						if ((*bul)->life) {

							(*bul)->WithPlayer(z);
							(*bul)->drawing();
						}
						else {
							delete((*bul));
							bullets.remove(*bul);
							break;
						}
					}
					if (Keyboard::isKeyPressed(Keyboard::Space) && z.ShootTimer >= 15){


						for (pb = rock.begin(); pb != rock.end(); pb++) {
							if ((*pb)->life) {

								//(*pb)->WithPlayer(z);
								(*pb)->drawing();
								FloatRect polozh = (*pb)->polozenie();
								float uskor = (*pb)->uskorenie();
								rock.push_back(new PBullet(polozh, uskor));
								z.ShootTimer = 0;
							}
							else {
								delete((*pb));
								rock.remove(*pb);
								break;
							}
						}
					}
					window.draw(z.hpbar);
					if (z.hp < 0)
						window.draw(gameOverText);

					
					window.display();
				}
				}
			}
		
		
		}
		
	
	return 0;
}