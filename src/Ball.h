//
// Created by nathan on 09/05/15.
//

#ifndef SFML_PONG_BALL_H
#define SFML_PONG_BALL_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

class Ball : public sf::Sprite{

public:

    Ball();

    void updateBall(sf::Time elapsedTime);

    void reverseX();
    void reverseY();

    void reset();

private:

    sf::Texture mBallTexture;

    float mSpeed;
    sf::Vector2f mMovement;


};


#endif //SFML_PONG_BALL_H
