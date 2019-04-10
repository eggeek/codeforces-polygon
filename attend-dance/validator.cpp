#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxl = 100000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, maxl, "n");
    inf.readEoln();
    int a, b, c;
    for (int i=0; i<n; i++) {
      a = inf.readInt(0, n, "A");
      inf.readSpace();
      b = inf.readInt(0, n, "B");
      inf.readSpace();
      c = inf.readInt(0, n, "C");
      inf.readEoln();
    }
    inf.readEof();
}
