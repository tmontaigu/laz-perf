#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

std::string testFile(const std::string& filename)
{
    return std::string("C:/Users/Thomas/Projects/examples/lazperf-rs/lazperf-c/laz-perf/test/raw-sets/") + filename;
}
