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
mIsTurbo(false),
mIsCollidingTop(false),
mIsCollidingBottom(false),
mPlayerTexture(),
mTop(),
mBottom(),
mLeft(),
mRight()
{

    mPlayerTexture.loadFromFile("images/paddle.png");
    this->setTexture(mPlayerTexture);



}

//is given the key that has been pressed and handles the input for it
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){

    if(key == sf::Keyboard::Space)
        mIsTurbo = isPressed;
	else if(key == sf::Keyboard::W)
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
    //or down && is not going to collide with top or bottom respectfully
    if(mIsMovingUp && !mIsCollidingTop){
        mVelocity.y = -mSpeed;
    }
    else if(mIsMovingDown && !mIsCollidingBottom){
        mVelocity.y = mSpeed;
    }

    //this is a toggle for faster movement in the game for the user
    if(mIsTurbo){
        mVelocity.y = mVelocity.y * 3;
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

/*
 * Grop of functions to get the sides of objects
 */
sf::RectangleShape* Player::getTop(){


    mTop.setPosition(this->getPosition());
    mTop.setSize(sf::Vector2f(this->getGlobalBounds().width, 2));

    return &mTop;


}
sf::RectangleShape* Player::getBottom(){

    mBottom.setPosition(this->getPosition().x, (this->getPosition().y +
                        this->getGlobalBounds().height));
    mBottom.setSize(sf::Vector2f(this->getGlobalBounds().width, 2));

    return &mBottom;

}
sf::RectangleShape* Player::getLeft(){

    mLeft.setPosition(this->getPosition());
    mLeft.setSize(sf::Vector2f(2, this->getGlobalBounds().height));

    return &mLeft;
}
sf::RectangleShape* Player::getRight(){

    mRight.setPosition((this->getPosition().x + this->getGlobalBounds().width),
                       (this->getPosition().y + this->getGlobalBounds().height));

    mRight.setSize(sf::Vector2f(2, this->getGlobalBounds().height));

    return &mRight;

}



Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::isCollidingTop(bool status) {
    mIsCollidingTop = status;
}

void Player::isCollidingBottom(bool status) {
    mIsCollidingBottom = status;
}

float Player::getHeight() {
    return this->getGlobalBounds().height;
}
