#ifndef MANAGER_TESTS_HPP
#define MANAGER_TESTS_HPP

#include "gtest/gtest.h"

#include "../header/Manager.h"

//tested a lot of major functionalities with valgrind

TEST(MenuAddSuite, OneNodeMenu) {
    Manager m = m.menuAdd(MenuItem *newNode = (1, 'a', "pasta", 12.50));
    bool result = m.isEmpty();
    EXPECT_FALSE(result);
}

#endif