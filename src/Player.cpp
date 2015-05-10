/*
 * Player.cpp
 *
 *  Created on: 2 Apr 2015
 *      Author: nathan
 *
 */

#include "Player.h"

Player::Player():
mSpeed(200.f),
mVelocity(0.f, 0.f),
mSize(1,1),
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



/*
 * Performs movement for the player
 * TODO: Collision detection
 */
void Player::updatePlayer(sf::Time elapsedTime){

    //Not using deceleration
    //so setting mVelocity as 0 each time
    mVelocity.x = 0;
    mVelocity.y = 0;

    //Handle if player keys are pressed to move up
    //or down
    if(mIsMovingUp){
        mVelocity.y = -mSpeed;
    }
    else if(mIsMovingDown){
        mVelocity.y = mSpeed;
    }


    //move the play based on current mVelocity size
    this->move(mVelocity * elapsedTime.asSeconds());

}

/**
 * returns the players velocity
 */
sf::Vector2f Player::getVelocity(){

    return this->mVelocity;

}


void Player::autoMove(sf::Sprite spriteToFollow, sf::Time elapsedTime) {

    mVelocity.x = 0;
    mVelocity.y = 0;


    if(this->getPosition().y +(this->getGlobalBounds().height /2) < spriteToFollow.getPosition().y){
        mVelocity.y = mSpeed;
    }
    else if(this->getPosition().y +(this->getGlobalBounds().height/2)  > spriteToFollow.getPosition().y){
        mVelocity.y = -mSpeed;
    }

    this->move(mVelocity * elapsedTime.asSeconds());

}


Player::~Player() {
	// TODO Auto-generated destructor stub
}

