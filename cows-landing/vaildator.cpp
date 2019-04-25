#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 9;
const int maxm = 1000;
int n, m;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    n = inf.readInt(1, maxn, "n");
    inf.readEoln();
    m = inf.readInt(1, min(maxm, 1<<(n<<1)));
    inf.readEoln();
    set<int> s;
    for (int i=0; i<m; i++) {
      int x = inf.readInt(1, 1<<(n<<1), "rank");
      inf.readEoln();
      ensuref(s.find(x) == s.end(), "no duplicate location");
      s.insert(x);
    }
    inf.readEof();
}
