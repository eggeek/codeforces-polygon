#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
  // This command initializes checker environment.
  registerTestlibCmd(argc, argv);
  // Now there are three global variables specifying testlib streams:
  // inf - stream with the testdata.
  // ouf - stream with the contestant output.
  // ans - stream with the jury answer.
  // All those streams provide the similar interface for reading data.

  inf.readInt();
  inf.readEoln();
  int m = inf.readInt();

  for (int i=0; i<m; i++) {
    int x0 = ouf.readInt();
    ouf.readSpace();
    int y0 = ouf.readInt();
    ouf.readEoln();

    int x1 = ans.readInt();
    ans.readSpace();
    int y1 = ans.readInt();
    ans.readEoln();

    if (!(x0 == x1 && y0 == y1)) {
      quitf(_wa, "Expected: (%d, %d), found: (%d, %d)", x1, y1, x0, y0);
    }
  }
  quitf(_ok, "Answer is correct");
  return 0;
}
