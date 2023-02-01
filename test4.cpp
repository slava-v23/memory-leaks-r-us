#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Box {
public:
  int val;
  int *iptr;
  Box(int val) : val{val} {
    cout << "Box created: " << val << endl;
    iptr = new int[10];
  }
  ~Box() {
     cout << "Box deleted: " << val << endl;
    delete[] iptr;
    iptr = nullptr; // <🟢 ? added
  }
  Box(const Box& other) {
    val = other.val;
    iptr = new int[10];
    for (int i = 0; i < 10; i++) {
      iptr[i] = other.iptr[i];
    }
    cout << "Box copied: " << val << endl;
  }
};

void test4() {
  Box b1(10);
  Box b2(b1);
}