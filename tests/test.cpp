#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "chef_tests.hpp"
#include "customer_tests.hpp"
#include "employee_tests.hpp"
#include "manager_tests.hpp"
#include "order_tests.hpp"
#include "restaurant_tests.hpp"
#include "../header/Restaurant.h"
#include "server_tests.hpp"
#include "table_tests.hpp"
#include "menuItem_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}