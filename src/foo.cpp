#include "foo.h"

#include <algorithm>
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

    currentFrame_ = std::min(10, currentFrame_);
    return;
}

int Game::scoreForFrame(int frame) {
    int score = 0;
    ball_ = 0;

    for (int currentFrame = 0; currentFrame < frame; currentFrame++) {
        if (strike()) {
            score += 10 + nextTwoBallsForStrike();
            ball_++;
        } else if (spare()) {
            score += 10 + nextBallForSpare();
            ball_ += 2;
        } else {
            score += nextTwoBalls();
            ball_ += 2;
        }
    }

    return score;
}

bool Game::strike() { return (nextBall() == 10); }

bool Game::spare() { return (nextTwoBalls() == 10); }

int Game::nextBall() { return throws_[ball_]; }

int Game::nextTwoBalls() { return throws_[ball_] + throws_[ball_ + 1]; }

int Game::nextTwoBallsForStrike() {
    return throws_[ball_ + 1] + throws_[ball_ + 2];
}

int Game::nextBallForSpare() { return throws_[ball_ + 2]; }