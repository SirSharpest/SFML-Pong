/*
 * Player.cpp
 *
 *  Created on: 2 Apr 2015
 *      Author: nathan
 *
 *  Currently loads a wizard sprite
 *
 */

#include "Player.h"

Player::Player():
mSpeed(200.f),
movement(0.f, 0.f),
mSize(1,1),
mPosX(0),
mPosY(0),
mColor(sf::Color::Blue),
mIsMovingUp(false),
mIsMovingDown(false),
mPlayerTexture()
{

    mPlayerTexture.loadFromFile("images/paddle.png");
    this->setTexture(mPlayerTexture);

}

//is given the key that has been pressed and handles the input for it
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){

	if(key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if(key == sf::Keyboard::S)
		mIsMovingDown = isPressed;

}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value"
/*
 * Performs movement for the player
 * TODO: Collision detection
 */
void Player::updatePlayer(sf::Time elapsedTime){

    //Not using deceleration
    //so setting movement as 0 each time
    movement.x = 0;
    movement.y = 0;

    //Handle if player keys are pressed to move up
    //or down
    if(mIsMovingUp){
        movement.y = -mSpeed;
    }
    else if(mIsMovingDown){
        movement.y = mSpeed;
    }


    //move the play based on current movement size
    this->move(movement * elapsedTime.asSeconds());

}

void Player::autoMove(sf::Sprite spriteToFollow, sf::Time elapsedTime) {

    movement.x = 0;
    movement.y = 0;


    if(this->getPosition().y < spriteToFollow.getPosition().y){
        movement.y = mSpeed;
    }
    else if(this->getPosition().y > spriteToFollow.getPosition().y){
        movement.y = -mSpeed;
    }

    this->move(movement * elapsedTime.asSeconds());

}


Player::~Player() {
	// TODO Auto-generated destructor stub
}

