//
// Created by nathan on 09/05/15.
//

#include "Ball.h"

Ball::Ball():
mBallTexture(),
mMovement(100,200){

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

}

void Ball::reverseX() {
    mMovement.x = -mMovement.x;
}

void Ball::reset(){
    this->setPosition(300,300);
    this->reverseX();
    this->reverseY();
}
