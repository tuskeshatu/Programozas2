#include <iostream>
#include <stdexcept>
#include <string>

#include "sharedPointer.h"

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
   /// RUNNING THIS PROGRAM WILL RESULT IN A MEMORY FAULT TO DEMONSTRATE THE WEAKNESS OF SHARED POINTERS!!! //
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    std::cout << "\n\n\n" + std::string(53, '-') + "\n" << "| My SharedPointer implementation by Levente Kovacs |\n"
    << std::string(53, '-') + "\n\n" << std::endl;
    double *testDoublePtr = new double(3.14);
    SharedPointer test(testDoublePtr);
    SharedPointer copyTest(test);
    std::cout << "Test value is: " << *test << " , which is the same as: " << *copyTest << std::endl;
    std::cout << "So are they equal?\n";
    if (test == copyTest)
        std::cout << "Yes!";
    else
        std::cout << "No!";
    std::cout << "\n\n" << std::endl;

    std::cout << "But is the SharedPointer pointing to the same value as testDoublePtr?\n";
    if (test == testDoublePtr)
        std::cout << "Yes!";
    else
        std::cout << "No!";
    std::cout << "\n\n" << std::endl;

    SharedPointer TestAssignment;
    std::cout << "I initialized another with default constructor, so is it nullptr?" << std::endl;
    double *testDouble2(new double(42.6));

    //////////////////////////////////////////////////////////////////////////////////////////////////
   /// IF DEBUGGING IN VSCODE JUST SKIP OVER THE EXCEPTION BY PRESSING THE RESUME DEBUGGING BUTTON //
  //////////////////////////////////////////////////////////////////////////////////////////////////

    try
    {
        *testDouble2 = *TestAssignment;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << "\n\n" << std::endl;
    }

    TestAssignment = testDouble2;
    std::cout << "I assigned the value " << *testDouble2 << " to other SharedPointer, so its value is now "
              << *TestAssignment << "\n\n" << std::endl;

    SharedPointer otherTest(testDoublePtr);
    std::cout << "But be careful! Initializing different SharedPointers with the same pointer will lead to double delete!\n\n"
              << "Don't initialize SharedPointers with addresses from the stack and be cautious with initializing with\n"
              << "pointer variables! The SharedPointer WILL delete the pointer when destructor is called and can leave\n"
              << "dangling pointers behind.\n\n"
              << "Also comparison can only be used to determine if two SharedPointers are pointing to the same address!\n"
              << "For example: " << std::endl;
    if (test == otherTest)
        std::cout << "Returns true!";
    else
        std::cout << "Returns false!";

    std::cout << std::endl <<"\nTests count is " << test.getCount() << ", while otherTests count is " << otherTest.getCount()
    << "!\nThey are pointing to the same address, so it will result in one deallocating the memory before the other one."
    << "\nResulting in a memory fault.\n" << std::string(110, '-') + "\n\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
   /// RUNNING THIS PROGRAM WILL RESULT IN A MEMORY FAULT TO DEMONSTRATE THE WEAKNESS OF SHARED POINTERS!!! //
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}
