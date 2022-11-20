#ifndef _FOO_H_
#define _FOO_H_
class Foo {
  public:
    Foo() = default;
    ~Foo() = default;

    int PrintFoo();
};

class Game {
  public:
    int score();
    int scoreForFrame(int frame);
    bool add(int pins);
    int getCurrentFrame() { return currentFrame_; };

  private:
    void adjustCurrentFrame(int pins);
    int handleSecondThrow();
    bool strike(); // 10 in a throw
    bool spare();  // 10 in two throws
    int nextBall();
    int nextTwoBalls();
    int nextTwoBallsForStrike();
    int nextBallForSpare();

  private:
    int score_ = 0;  // total score
    int throws_[21]; // max throws in a game, not more than 21
    int currentThrow_ = 0;   // the next throw
    int currentFrame_ = 1;   // the frame not finish throw
    bool firstThrow_ = true; // flag for first throw in a frame
    int ball_ = 0; // an iterator
};

#endif