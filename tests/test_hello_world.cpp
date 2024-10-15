#include <gtest/gtest.h>
#include "hello_world.h"

TEST(HelloWorldTest, GetMessage) {
    HelloWorld hello_world;
    EXPECT_EQ(hello_world.GetMessage(), "Hello world!");
}
