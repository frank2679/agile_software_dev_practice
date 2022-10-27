/**
 * @file main.cpp
 * @author yanghang (you@domain.com)
 * @brief template project
 * @version 0.1
 * @date 2021-04-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "foo.h"

#include "gtest/gtest.h"
#include <iostream>

class TestGame : public testing::Test {
  protected:
    void SetUp() override {}

    void testAddOneThrow() {
        g_.add(5);
        // EXPECT_EQ(5, g_.score()); // not check point when the frame is not
        // complete
        EXPECT_EQ(5, g_.scoreForFrame(1));
        EXPECT_EQ(1, g_.getCurrentFrame());
    }

    void testAddTwoThrowsNoMark() {
        g_.add(5);
        g_.add(4);
        EXPECT_EQ(9, g_.score());
        EXPECT_EQ(2, g_.getCurrentFrame());
    }

    void testFourThrowsNoMark() {
        g_.add(5);
        g_.add(4);
        g_.add(7);
        g_.add(2);
        EXPECT_EQ(18, g_.score());
        EXPECT_EQ(9, g_.scoreForFrame(1));
        EXPECT_EQ(18, g_.scoreForFrame(2));
        EXPECT_EQ(3, g_.getCurrentFrame());
    }

    void testSimpleSpare() {
        g_.add(3);
        g_.add(7);
        g_.add(3);
        EXPECT_EQ(13, g_.scoreForFrame(1));
        EXPECT_EQ(2, g_.getCurrentFrame());
    }

    void testSimpleFrameAfterSpare() {
        g_.add(3);
        g_.add(7);
        g_.add(3);
        g_.add(2);
        EXPECT_EQ(13, g_.scoreForFrame(1));
        EXPECT_EQ(18, g_.scoreForFrame(2));
        EXPECT_EQ(3, g_.getCurrentFrame());
        EXPECT_EQ(18, g_.score());
    }

    void testFullThrow() {
        g_.add(10);
        g_.add(3);
        g_.add(6);
        EXPECT_EQ(19, g_.scoreForFrame(1));
        EXPECT_EQ(3, g_.getCurrentFrame());
        EXPECT_EQ(28, g_.score());
    }

    void testPerfectGame() {
        for (int i = 0; i < 12; i++) {
            g_.add(10);
        }
        EXPECT_EQ(30, g_.scoreForFrame(1));
        EXPECT_EQ(10, g_.getCurrentFrame());
        EXPECT_EQ(300, g_.score());
    }

    void testEndOfArray() {
        for (int i = 0; i < 9; i++) {
            g_.add(0);
            g_.add(0);
        }
        g_.add(2);
        g_.add(8);
        g_.add(10);
        EXPECT_EQ(10, g_.getCurrentFrame());
        EXPECT_EQ(20, g_.scoreForFrame(10));
        EXPECT_EQ(20, g_.score());
    }

    void testSampleGame() {
        g_.add(1);
        g_.add(4);
        g_.add(4);
        g_.add(5);
        g_.add(6);
        g_.add(4);
        g_.add(5);
        g_.add(5);
        g_.add(10);
        g_.add(0);
        g_.add(1);
        g_.add(7);
        g_.add(3);
        g_.add(6);
        g_.add(4);
        g_.add(10);
        g_.add(2);
        g_.add(8);
        g_.add(6);
        EXPECT_EQ(133, g_.score());
    }

    void testHeartBreak() {
        for (int i = 0; i < 11; i++) {
            g_.add(10);
        }
        g_.add(9);
        EXPECT_EQ(299, g_.score());
    }

    void testTenthFrameSpare() {
        for (int i = 0; i < 9; i++) {
            g_.add(10);
        }
        g_.add(9);
        g_.add(1);
        g_.add(1);
        EXPECT_EQ(270, g_.score());
    }

  private:
    Game g_;
};

TEST_F(TestGame, testAddOneThrow) { testAddOneThrow(); }

TEST_F(TestGame, testAddTwoThrowsNoMark) { testAddTwoThrowsNoMark(); }

TEST_F(TestGame, testFourThrowsNoMark) { testFourThrowsNoMark(); }

TEST_F(TestGame, testSimpleSpare) { testSimpleSpare(); }

TEST_F(TestGame, testSimpleFrameAfterSpare) { testSimpleFrameAfterSpare(); }

TEST_F(TestGame, testFullThrow) { testFullThrow(); }

TEST_F(TestGame, testPerfectGame) { testPerfectGame(); }

TEST_F(TestGame, testEndOfArray) { testEndOfArray(); }

TEST_F(TestGame, testSampleGame) { testSampleGame(); }

TEST_F(TestGame, testHeartBreak) { testHeartBreak(); }

TEST_F(TestGame, testTenthFrameSpare) { testTenthFrameSpare(); }
