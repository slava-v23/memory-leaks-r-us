/**
 * Lots of memory leaks. Gotta fix them all!
 * But, you cannot fix them all at once.
 * Work on one test at a time
 *
 * Use ./runmemcheck.sh to run your program under valgrind
 *
 */

#include <iostream>

using namespace std;

// forward declarations
void test1();
void test2();
void test3();
void test4();
void test5();

int main() {
  cout << "Starting memory-leaks-r-us...." << endl;
   test1();
  //  test2(); // < bugs here 
   test3();
   test4();
   test5();
    // cout << "🌻END"<<endl;
  cout << "Successfully completed memory-leaks-r-us...." << endl;
  return 0;
}