#include "scorer.h"

#include <algorithm>
#include <iostream>

void Scorer::addThrow(int pins) { throws_[currentThrow_++] = pins; }

int Scorer::scoreForFrame(int frame) {
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

bool Scorer::strike() { return (nextBall() == 10); }

bool Scorer::spare() { return (nextTwoBalls() == 10); }

int Scorer::nextBall() { return throws_[ball_]; }

int Scorer::nextTwoBalls() { return throws_[ball_] + throws_[ball_ + 1]; }

int Scorer::nextTwoBallsForStrike() {
    return throws_[ball_ + 1] + throws_[ball_ + 2];
}

int Scorer::nextBallForSpare() { return throws_[ball_ + 2]; }