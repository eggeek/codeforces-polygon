#include "testlib.h"
#include <iostream>

using namespace std;
const int maxn = 1000000;
int n;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  int f = atoi(argv[1]);
  if (f == 0) {
    n = rnd.next(0, maxn);
    cout << n << endl;
  } else {
    n = rnd.next(1, maxn / 3);
    cout << n * 3 << endl;
  }
  return 0;
}
