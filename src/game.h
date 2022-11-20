#ifndef _GAME_H_
#define _GAME_H_
#include "scorer.h"

class Game {
  public:
    int score();
    int scoreForFrame(int frame); // frame index from 1
    bool add(int pins);

  private:
    void adjustCurrentFrame(int pins);
    void advanceFrame();

  private:
    int currentFrame_ = 1;   // the frame of last throw
    bool firstThrow_ = true; // flag for first throw in a frame
    Scorer itsscorer;
};

#endif