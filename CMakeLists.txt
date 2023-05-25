CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

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
)

ADD_EXECUTABLE(test
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)