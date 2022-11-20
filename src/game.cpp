#include "game.h"

#include <algorithm>
#include <iostream>

// get score after the frame finish
int Game::score() { return itsscorer.scoreForFrame(currentFrame_); }

int Game::scoreForFrame(int frame) { return itsscorer.scoreForFrame(frame); }

bool Game::add(int pins) {
    itsscorer.addThrow(pins);
    adjustCurrentFrame(pins);
    return true;
}

void Game::adjustCurrentFrame(int pins) {
    if (firstThrow_) {
        if (10 == pins)
            advanceFrame();
        else
            firstThrow_ = false;
    } else {
        firstThrow_ = true;
        advanceFrame();
    }

    return;
}

void Game::advanceFrame() { currentFrame_ = std::min(10, currentFrame_ + 1); }