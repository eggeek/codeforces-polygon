#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 1000;
int n;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    n = inf.readInt(1, maxn, "n");
    inf.readEoln();

    for (int i=0; i<n; i++) {
      int m = inf.readInt(1, 10, "m");
      set<int> s;
      for (int j=0; j<m; j++) {
        inf.readSpace();
        int c = inf.readInt(1, 10, "c");
        ensuref(s.find(c) == s.end(), "no duplicate color");
        s.insert(c);
      }
      inf.readEoln();
    }
    inf.readEof();
}
