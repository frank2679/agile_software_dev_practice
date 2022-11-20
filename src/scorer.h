#ifndef _SCORER_H_
#define _SCORER_H_

class Scorer {
  public:
    void addThrow(int pins);
    int scoreForFrame(int frame); // frame index from 1

  private:
    bool strike(); // 10 in first throw
    bool spare();  // 10 in two throws
    int nextBall();
    int nextTwoBalls();
    int nextTwoBallsForStrike();
    int nextBallForSpare();

  private:
    int throws_[21];       // max throws in a game, not more than 21
    int currentThrow_ = 0; // the next throw
    int ball_ = 0;
};

#endif