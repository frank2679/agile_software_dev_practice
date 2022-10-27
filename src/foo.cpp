#include "foo.h"

#include <iostream>
int Foo::PrintFoo() {
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}

// get score after the frame finish
int Game::score() {
    return (currentFrame_ == 10) ? scoreForFrame(currentFrame_)
                                 : scoreForFrame(currentFrame_ - 1);
}

bool Game::add(int pins) {
    throws_[currentThrow_++] = pins;
    adjustCurrentFrame(pins);
    return true;
}

void Game::adjustCurrentFrame(int pins) {
    if (firstThrow_) {
        if (10 == pins)
            currentFrame_++;
        else
            firstThrow_ = false;
    } else {
        firstThrow_ = true;
        currentFrame_++;
    }

    if (currentFrame_ > 10)
        currentFrame_ = 10;
    return;
}

int Game::handleSecondThrow() {
    int score = 0;
    pinsSecondThrow_ = throws_[ball_++];
    int frameScore = pinsFirstThrow_ + pinsSecondThrow_;
    if (frameScore == 10) {
        score += frameScore + throws_[ball_];
    } else {
        score += frameScore;
    }
    return score;
}

int Game::scoreForFrame(int frame) {
    int score = 0;
    ball_ = 0;

    for (int currentFrame = 0; currentFrame < frame; currentFrame++) {
        pinsFirstThrow_ = throws_[ball_++];
        if (pinsFirstThrow_ == 10) {
            score += 10 + throws_[ball_] + throws_[ball_ + 1];
        } else {
            score += handleSecondThrow();
        }
    }

    return score;
}