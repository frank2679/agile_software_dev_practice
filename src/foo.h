#ifndef _FOO_H_
#define _FOO_H_
class Foo {
  public:
    Foo() = default;
    ~Foo() = default;

    int PrintFoo();
};

class Frame {
  public:
    int getScore() { return score_; }
    bool add(int pins) { score_ += pins; }

  private:
    int score_ = 0;
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

  private:
    int score_ = 0;  // total score
    int throws_[21]; // max throws in a game
    int currentThrow_ = 0;
    int currentFrame_ = 1;
    bool firstThrow_ = true;
    int pinsFirstThrow_;
    int pinsSecondThrow_;
    int ball_ = 0;
};

#endif