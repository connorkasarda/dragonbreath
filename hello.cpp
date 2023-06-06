// preprocessor directive -- includes contents of a code library
#include <iostream>

// rule: every c++ program must have a function named main (lower case),
// otherwise linking will fail
int main(int argc, char** argv)
{
    // the predefined variable cout from std stands for "character output"
    std::cout << "Hello World\n";
    // the value program sends back to OS to indicate status of run
    return 0;
}