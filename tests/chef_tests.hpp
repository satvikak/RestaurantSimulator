#ifndef CHEF_TESTS_HPP
#define CHEF_TESTS_HPP

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../header/Chef.h"

TEST(ChefGetter, getMistakes) {
    Chef c;
    int mistakes = c.getMistakes();
    EXPECT_EQ(mistakes, 0);
}

#endif