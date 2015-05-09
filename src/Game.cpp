/*
a * Game.cpp
 *
 *  Created on: 24 Mar 2015
 *      Author: Nathan Hughes
 */




#include "Game.h"
#include <iostream>
#include <sstream>


Game::Game():
g_Window(sf::VideoMode(640, 480), "SFML"),
g_Font(),
FRAMES_PER_SECOND(60),
TIME_PER_FRAME(sf::seconds(1.f/FRAMES_PER_SECOND)),
g_Fps(),
g_FpsTimer(),
g_FpsNumFrames(),
g_GameState(0),
g_SplashScreenTexture(),
g_SplashScreenSprite(),
g_BackgroundSprite(),
g_BackgroundTexture(),
g_SolidBackground(),
g_Player1(),
g_Player2(),
g_Ball()
{


	//setting window properties
	g_Window.setVerticalSyncEnabled(false);
	g_Window.setFramerateLimit(FRAMES_PER_SECOND);


	//setting font location
	g_Font.loadFromFile("fonts/KenPixel Square.ttf");
	//loading splash screen
	g_SplashScreenTexture.loadFromFile("images/intro.png");
	g_SplashScreenSprite.setTexture(g_SplashScreenTexture);
	g_SplashScreenSprite.setPosition(0.f,0.f);

	//setting g_Fps info
	g_Fps.setCharacterSize(20);
	g_Fps.setFont(g_Font);
	g_Fps.setPosition(300,0);
    g_Fps.setColor(sf::Color::Black);
    g_Fps.setCharacterSize(24);

    //set player 2's default position
    g_Player2.setPosition(610, 0);

    //set the solid background
    g_SolidBackground.setSize(sf::Vector2f(640, 480));
    g_SolidBackground.setFillColor(sf::Color::Green);
    g_SolidBackground.setPosition(0,0);


}


void Game::run(){


	//clocks and times used to get custom game loop working
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	//setting g_GameState to be intro on run
	g_GameState = 0;

			//main loop to run the entire length of games
			//life
	        while (g_Window.isOpen())
	        {
	            sf::Time dt = clock.restart();
	            timeSinceLastUpdate += dt;


	            while(timeSinceLastUpdate > TIME_PER_FRAME)
	            {

	            	timeSinceLastUpdate -= TIME_PER_FRAME;
	                processEvents();
	                update(TIME_PER_FRAME);

	            }
	            updateFPSCounter(dt);
	            render();


	        }

}



//process input events
void Game::processEvents(){

	sf::Event event;

	while(g_Window.pollEvent(event)){


			if(event.type == sf::Event::Closed)
				g_Window.close();


			if(g_GameState == INTRO){
				if(event.key.code == sf::Keyboard::Space){
					g_GameState = PLAYING;
				}
			}

			if(g_GameState == PLAYING){
				if(event.type == sf::Event::KeyPressed){
					g_Player1.handlePlayerInput(event.key.code, true);
				}
				else if(event.type == sf::Event::KeyReleased){
					g_Player1.handlePlayerInput(event.key.code, false);
				}

			}


		}


}

//perform logic and call for collision checks
void Game::update(sf::Time elapsedTime){


    if(g_GameState == PLAYING){
        //move the player
        g_Player1.updatePlayer(elapsedTime);
        g_Ball.updateBall(elapsedTime);
        g_Player2.autoMove(g_Ball, elapsedTime);

        //handle collisions
        handleCollisions();
    }



}


//Put all the collision checking and handling here
void Game::handleCollisions(){

    //Check for the ball on top of screen and bottom
    if(g_Ball.getPosition().y >= 460){
        g_Ball.reverseY();
    }
    else if(g_Ball.getPosition().y <= 0){
        g_Ball.reverseY();
    }

    //check for colliding with paddles
    if(isRectCollision(g_Ball, g_Player1)){
        g_Ball.reverseX();
        //check for top of ball collision
        if(g_Ball.getPosition().y == g_Player1.getPosition().y + g_Player1.getGlobalBounds().height){
            g_Ball.reverseY();
        }
    }
    else if (isRectCollision(g_Ball, g_Player2)){
        g_Ball.reverseX();
    }

    //check if ball has exited left or right of screen
    if(g_Ball.getPosition().x <= -30){
        g_Ball.reset();
    }
    else if(g_Ball.getPosition().x >= 645){
        g_Ball.reset();
    }


}


//check rectangles for collision without taking into account where the collision is
bool Game::isRectCollision(sf::Sprite &sprite1, sf::Sprite &sprite2){

		sf::FloatRect r1=sprite1.getGlobalBounds();
	    sf::FloatRect r2=sprite2.getGlobalBounds();
	    return r1.intersects(r2);

}


void Game::updateFPSCounter(sf::Time dt){

	g_FpsTimer += dt;
	g_FpsNumFrames += 1;

	if( g_FpsTimer >= sf::seconds(1.0f)){

		std::ostringstream ss;

		ss << g_FpsNumFrames;
		g_Fps.setString(ss.str());

		g_FpsTimer -= sf::seconds(1.0f);
		g_FpsNumFrames = 0;
	}

}

//re-apply changes to window
void Game::render(){

	//wipe window clear
	g_Window.clear(sf::Color::Black);

	switch (g_GameState) {
		case INTRO:
			//draw splash screen
			g_Window.draw(g_SplashScreenSprite);
			break;
		case PLAYING:
            g_Window.draw(g_SolidBackground);
			g_Window.draw(g_Player1);
            g_Window.draw(g_Player2);
            g_Window.draw(g_Ball);
			break;
		default:
			break;
	}

	//display new screen layout
	g_Window.draw(g_Fps);
	g_Window.display();


}



