#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 1000000;
const int maxv = 1000000000;
int n, a;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    n = inf.readInt(1, maxn, "n");
    inf.readEoln();
    for (int i=0; i<n; i++) {
      a = inf.readInt(1, maxv, "a");
      if (i < n-1) inf.readSpace();
      else inf.readEoln();
    }
    inf.readEof();
}
