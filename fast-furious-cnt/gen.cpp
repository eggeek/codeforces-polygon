#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxx = 50;
const int maxy = 50;
int m, sx, sy, tx, ty;

void genRandom() {
  m = rnd.next(1, maxx);
  sx = rnd.next(1, maxx);
  sy = rnd.next(1, maxy);
  tx = rnd.next(sx, maxx);
  ty = rnd.next(sy, maxy);
}

int main(int argc, char* argv[])
{
  if (string(argv[1]) == "maxm") {
    registerGen(argc, argv, 1);
    genRandom();
    cout << 50 << endl;
    cout << sx << " " << sy << endl;
    cout << tx << " " << ty << endl;
  } else {
    registerGen(argc, argv, 1);
    genRandom();
    cout << m << endl;
    cout << sx << " " << sy << endl;
    cout << tx << " " << ty << endl;
  }
}
