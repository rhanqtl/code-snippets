#include <iostream>

using namespace std;

bool is_valid(int x) {
  return 0 < x && x <= 120;
}

int main() {
  int age = 42;
  if (not is_valid(age)) {
    cout << "invalid age" << endl;
  }
}
