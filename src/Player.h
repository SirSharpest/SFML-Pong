/*
 * Player.h
 *
 *  Created on: 2 Apr 2015
 *      Author: nathan
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {
public:
	Player();
	virtual ~Player();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void updatePlayer(sf::Time elapsedTime);
    void autoMove(sf::Sprite spriteToFollow, sf::Time elapsedTime);


private:

	//properties of the player
	float mSpeed;
	sf::Vector2f movement;
	sf::Vector2f mSize;
	sf::Color mColor;

	//movement flags for player
	bool mIsMovingUp, mIsMovingDown;

	sf::Texture mPlayerTexture;



};

#endif /* PLAYER_H_ */
