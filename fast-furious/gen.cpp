#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
int m, sx, sy, tx, ty;

void genRandom() {
  m = rnd.next(1, 100);
  sx = rnd.next(1, 100);
  sy = rnd.next(1, 100);
  tx = rnd.next(sx, 100);
  ty = rnd.next(sy, 100);
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    genRandom();
    cout << m << endl;
    cout << sx << " " << sy << endl;
    cout << tx << " " << ty << endl;
}
