CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(Restaurant)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(play
    src/main.cpp
    src/Chef.cpp
    src/Customer.cpp
    src/Employee.cpp
    src/Manager.cpp
    src/Order.cpp
    src/Restaurant.cpp
    src/Server.cpp
    src/Table.cpp
    src/MenuItem.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
    src/Chef.cpp
    src/Customer.cpp
    src/Employee.cpp
    src/Manager.cpp
    src/Order.cpp
    src/Restaurant.cpp
    src/Server.cpp
    src/Table.cpp
    src/MenuItem.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(test gmock)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)