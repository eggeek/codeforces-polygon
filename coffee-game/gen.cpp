#include "testlib.h"
#include <iostream>

using namespace std;
const int maxn = 3000;
int n;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  n = rnd.next(6, maxn);
  cout << n << endl;
  return 0;
}
