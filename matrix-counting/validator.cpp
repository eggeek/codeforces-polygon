#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 100000;
int n, m;
vector<int> c;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    n = inf.readInt(1, maxn, "n");
    inf.readSpace();
    m = inf.readInt(1, maxn, "m");
    inf.readEoln();
    c.resize(m);
    for (int i=0; i<m; i++) {
      c[i] = inf.readInt(0, 1, "ci");
      if (i < m-1) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
}
