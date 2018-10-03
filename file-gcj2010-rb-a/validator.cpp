#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 100;
int n, m;
vector<string> exist, need;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  n = inf.readInt(0, maxn, "n");
  inf.readSpace();
  m = inf.readInt(1, maxn, "m");
  inf.readEoln();

  exist.resize(n);
  need.resize(m);
  for (int i=0; i<n; i++) {
    exist[i] = inf.readString();
  }
  for (int i=0; i<m; i++) {
    need[i] = inf.readString();
  }
  inf.readEof();
}
