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

#endif