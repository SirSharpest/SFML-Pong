//
// Created by nathan on 09/05/15.
//

#include "Ball.h"


Ball::Ball():
mBallTexture(),
mMovement(100,200),
numRebounds(1){

    mBallTexture.loadFromFile("images/ball.png");
    this->setTexture(mBallTexture);
    this->setScale(1,1);
    this->setPosition(300,300);

}

void Ball::updateBall(sf::Time elapsedTime) {


    this->move(mMovement * elapsedTime.asSeconds());

}

void Ball::reverseY() {
    mMovement.y = -mMovement.y;
    numRebounds++;
}

void Ball::reverseX() {
    mMovement.x = -mMovement.x;
    numRebounds++;
}

void Ball::increaseSpeed() {

    mMovement.x = mMovement.x + (numRebounds*mMovement.x/20);
    mMovement.y = mMovement.y + (numRebounds*mMovement.y/20);
}

void Ball::reset(){
    this->setPosition(300,300);
    this->reverseX();
    this->reverseY();
    numRebounds = 1;
    mMovement.x = 100;
    mMovement.y = 200;
}
