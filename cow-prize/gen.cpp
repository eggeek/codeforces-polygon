#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 100000;
int a, b, c;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string f = string(argv[1]);
  if (f == "random") {
    a = rnd.next(0, maxn);
    b = rnd.next(0, a);
    c = rnd.next(0, b);
  }
  else if (f == "same") {
    a = rnd.next(0, maxn);
    b = a, c = a;
  }
  else if (f == "doubleAB") {
    c = rnd.next(0, maxn / 2);
    a = rnd.next(c*2, maxn);
    b = rnd.next(c*2, a);
  }
  else if (f == "doubleA") {
    a = rnd.next(0, maxn);
    b = a / 2;
    c = rnd.next(0, b);
  }
  cout << a << " " << b << " " << c << endl; 
  return 0;
}
