#ifndef CHEF_TESTS_HPP
#define CHEF_TESTS_HPP

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../header/Chef.h"

TEST(ChefConstructorTests, noParameters) {
    Chef c = Chef();
    EXPECT_EQ(c.getMistakes(), 0);
}

TEST(ChefGetter, getMistakes) {
    Chef c;
    int mistakes = c.getMistakes();
    EXPECT_EQ(mistakes, 0);
}

#endif