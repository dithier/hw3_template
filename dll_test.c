// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall dll_test.c -o dll_test
//
// Run with: ./dll_test
// Then run with valgrind ./dll_test
// And don't forget valgrind -s ./dll_test!
//
// Comment out tests that you're not ready to run yet
// add them back in as you finish functions.
// You can also add tests as you go to make sure
// the functions you have written are working.
//
//
// Include parts of the C Standard Library
// Do not add any additional libraries
#include <stdio.h>   // For IO operations
#include <stdlib.h>  // for malloc/free
#include <string.h>  //for strings

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// A sample collection of tests for your program
// We will be adding our own to test your program.

// Tests creation and deletion of list
// Ideally does not cause any segfaults, and this
// is considered passing.
// Dll should also be empty.
int unitTest0(int status) {
    int passed = 0;
    team_t* test = create_team();
    if (team_empty(test)) {
        passed = 1;
    }
    free_team(test);

    return passed;
}

// Tests push_front and size functions with 1 player
int unitTest1(int status) {
    int passed = 0;
    team_t* test = create_team();
    char player[20] = "Pettersson";
    team_push_front(test, 40, player);
    if (1 == team_size(test)) {
        passed = 1;
    } else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

// Tests push_back and size functions with 1 player
int unitTest2(int status) {
    int passed = 0;
    team_t* test = create_team();
    char player[20] = "Horvat";

    team_push_back(test, 142, player);
    if (1 == team_size(test)) {
        passed = 1;
    } else {
        passed = 0;
    }
    free_team(test);

    return passed;
}

// An array of function pointers to all of the tests
// that main() can use iterate over them.
int (*unitTests[])(int) = {unitTest0, unitTest1, unitTest2, NULL};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main() {
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL) {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1)) {
            printf("passed test\n");
            testsPassed++;
        } else {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}
