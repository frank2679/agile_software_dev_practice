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

TEST(TestFrame, testScoreNoThrows) {
    Frame f;
    EXPECT_EQ(0, f.getScore());
}

TEST(TestFrame, testAddOneThrow) {
    Frame f;
    f.add(5);
    EXPECT_EQ(5, f.getScore());
}