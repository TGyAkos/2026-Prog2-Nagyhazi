#include <iostream>

#include "MessageFile.h"
#include "memtrace.h"
#include "gtest_lite.h"

std::string MessageFile::output_file_name = "output.txt";

#ifdef TEST
#include "test.h"
#endif


int main() {
    #ifdef TEST
    tests();
    #endif

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
