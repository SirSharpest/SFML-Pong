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
	sf::Vector2f getVelocity();
	void isCollidingTop(bool status);
	void isCollidingBottom(bool status);
	float getHeight();

	sf::RectangleShape* getTop();
	sf::RectangleShape* getBottom();
	sf::RectangleShape* getLeft();
	sf::RectangleShape* getRight();


private:

	//properties of the player
	float mSpeed;
	sf::Vector2f mVelocity;
	sf::Vector2f mSize;
	sf::Color mColor;

	//movement flags for player
	bool mIsMovingUp, mIsMovingDown, mIsTurbo;
	//position flags for player
	bool mIsCollidingTop, mIsCollidingBottom;

	sf::Texture mPlayerTexture;

	//collision rects
	sf::RectangleShape mTop, mBottom,
			mLeft, mRight;

};

#endif /* PLAYER_H_ */
