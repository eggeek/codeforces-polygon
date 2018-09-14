#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int maxn = 1000000000;

int f(int n) {
  int res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    // This function reads a single integer from the participant output that 
    // should be between -2000 and 2000. If it doesn't belong to the specified
    // range, checker finishes with verdict _pe and comment saying that [sum of numbers]
    // is outside of the specified range.
    int n = inf.readInt();
    if (f(n) % 3 == 0) {
      int ansA = ouf.readInt(0, maxn, "a");
      int ansB = ouf.readInt(0, maxn, "b");
      int ansC = ouf.readInt(0, maxn, "c");

      if (ansA + ansB + ansC != n)
        quitf(_wa, "Total sum is %d, not %d", ansA + ansB + ansC, n);
      int fa = f(ansA), fb = f(ansB), fc = f(ansC);
      if (fa == fb && fb == fc)
        quitf(_ok, "");
      else
        quitf(_wa, "Found (%d, %d, %d), not equal", fa, fb, fc);
    }
    else {
      int ans = ouf.readInt(-1, 1, "ans");
      if (ans != -1)
        quitf(_wa, "Expect -1, found %d", ans);
      else
        quitf(_ok, "");
    }
  return 0;
}
