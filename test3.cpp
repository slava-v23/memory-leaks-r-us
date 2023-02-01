#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class StringT3 {
public:
  string *myStrings = new string[3];
  StringT3() = default;
  StringT3(string a, string b, string c) {
    myStrings[0] = a;
    myStrings[1] = b;
    myStrings[2] = c;
    cout << "Created " << myStrings[0] << myStrings[1] << myStrings[2] << endl;
  }

  ~StringT3() {
    cout << "Deleting " << myStrings[0] << myStrings[1] << myStrings[2] << endl;
//    delete[](myStrings); // <🟢 memory leak if added
  }
};

void test3() {
  StringT3 s1("a", "b", "c");
  StringT3 t1;
  t1 = s1;
  StringT3 u1(s1);
  u1.myStrings[0] = "q";

//    cout << "🌻1"<<endl;
  auto *s2ptr = new StringT3("w", "x", "y");
  StringT3 *t2ptr;
  t2ptr = s2ptr;

//    cout << "🌻2"<<endl;
  vector<StringT3> v1;
  v1.push_back(s1);
  v1.push_back(t1);
  v1.push_back(u1);

//    cout << "🌻3"<<endl;
  vector<StringT3 *> v2;
  v2.push_back(s2ptr);
  v2.push_back(t2ptr);

//    delete(s2ptr); // << 🟢 error if dded

//    cout << "🌻4"<<endl;

  cout << "test3 is done" << endl;
}