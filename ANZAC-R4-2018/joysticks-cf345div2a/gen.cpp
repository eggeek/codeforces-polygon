#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 100;
int a, b;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string f = string(argv[1]);
  if (f == "random") {
    a = rnd.next(1, maxn);
    b = rnd.next(1, maxn);
  }
  else if (f == "same") {
    a = rnd.next(1, maxn);
    b = a;
  }
  cout << a << " " << b << endl;
  return 0;
}
