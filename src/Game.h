/*
 * Game.h
 *
 *  Created on: 24 Mar 2015
 *      Author: nathan
 */

#include <SFML/Graphics.hpp>
#include <string.h>
#include "Player.h"
#include "Ball.h"

#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	Game();
	void run();



//private functions
private:
	void update(sf::Time elapsedTime);
	void render();
	void processEvents();
	bool isRectCollision(sf::Sprite &rect1, sf::Sprite &rect2);
	bool isRectCollision(sf::RectangleShape &rect1, sf::Sprite &rect2);
	void handleCollisions();
	void updateFPSCounter(sf::Time dt);
    void updateScores(bool p1Scored);




private:
	sf::RenderWindow g_Window;

	//Creating font
	sf::Font g_Font;


	const int FRAMES_PER_SECOND;
	const sf::Time TIME_PER_FRAME;

	//g_Fps text object
	sf::Text g_Fps;
	sf::Time g_FpsTimer;
	int g_FpsNumFrames;

	sf::Text g_P1Score;
	sf::Text g_P2Score;

	int g_GameState;
	enum states{INTRO = 0, PLAYING = 1};

	sf::Texture g_SplashScreenTexture;
	sf::Sprite g_SplashScreenSprite;
	sf::Sprite g_BackgroundSprite;
	sf::Texture g_BackgroundTexture;
    sf::RectangleShape g_SolidBackground;

	Player g_Player1;
    Player g_Player2;
	Ball g_Ball;

    int g_P1NumScore, g_P2NumScore;



};

#endif /* GAME_H_ */
