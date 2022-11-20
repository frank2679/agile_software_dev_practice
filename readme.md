通过 chp6 的一个编程实践，尝试 TDD 开发模式。

实现过程中遇到的问题

去掉 `getCurrentFrame()` 这一点不容易想到，或者说不太愿意去掉。因为它一定程度上帮助我们debug。

单独跑 `FullThrow` 没错，连着跑的时候出错。应该是 current frame 不对了。找到原因是 currentFrame 初始化错误，应该是 0，原来设置是1。
启发
1. 需要 debug 去看内部行为；
2. 需要测试充分；这一点很难；往往有惰性；这也是为啥要结对编程；
3. 要有防御编程，
4. 编程中需要有 setup teardown，隔离case 之间的影响；

```bash
// single case passed
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from TestGame
[ RUN      ] TestGame.testFullThrow
[       OK ] TestGame.testFullThrow (0 ms)
[----------] 1 test from TestGame (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.

// all cases running failed
[----------] Global test environment tear-down
[==========] 11 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 10 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] TestGame.testFullThrow
```

todo
1. 考虑 throws_ 采用 vector 而不是 array。第一次尝试失败了。
2. currentFrame 的设定有点问题，还是没能复现发生过的 bug，此前是 game::currentFrame_ = 1, fullThrow case 就不过了。原因是 Game 构造的方式不一致带来的，一种是 make_shared 就没问题。一开始以为是 setup 的次数不对导致的。其实不是。就是当使用 Game g 构造时，scorer 内部的 throws_ 的值不太对。

Fix
1. 改用 make_shared<Game> 或者
2. 修改 currentFrame_ = 0 或者
3. 初始化 array 全为0
```cpp
    int throws_[21] = {0}; // max throws in a game, not more than 21
```

疑问是
1. 为啥 Game g_; 导致 throws_[21] 里面的值是上一个 case 遗留下来的? 
2. 难道是 make_shared 做了内存清理？

A: 使用指针的做法是 heap，Game g_ 申请的是 stack，可是为啥 heap 的内存就是清零了的？

stack 地址：
0x561de46450e8
heap 地址：
0x5577fbc621e8

```bash
[ RUN      ] TestGame.testAddOneThrow
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, [       OK ] TestGame.testAddOneThrow (0 ms)
[ RUN      ] TestGame.testAddTwoThrowsNoMark
5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, [       OK ] TestGame.testAddTwoThrowsNoMark (0 ms)
[ RUN      ] TestGame.testFourThrowsNoMark
5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, [       OK ] TestGame.testFourThrowsNoMark (0 ms)
[ RUN      ] TestGame.testSimpleSpare
5, 4, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, [       OK ] TestGame.testSimpleSpare (0 ms)
[ RUN      ] TestGame.testSimpleFrameAfterSpare
3, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, [       OK ] TestGame.testSimpleFrameAfterSpare (0 ms)
[ RUN      ] TestGame.testFullThrow
3, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /home/frank/learning/agile_sw_dev/001_ball_game/src/main.cpp:65: Failure
Expected equality of these values:
  28
  g_.score()
    Which is: 30
[  FAILED  ] TestGame.testFullThrow (0 ms)
[ RUN      ] TestGame.testPerfectGame
```
