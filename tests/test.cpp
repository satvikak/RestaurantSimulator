#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "chef_tests.hpp"
#include "customer_tests.hpp"
#include "manager_tests.hpp"
#include "menuItem_tests.hpp"
#include "orderNode_tests.hpp"
#include "restaurant_tests.hpp"
#include "server_tests.hpp"
#include "table_tests.hpp"

int main(int argc, char **argv) {
  srand(time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}