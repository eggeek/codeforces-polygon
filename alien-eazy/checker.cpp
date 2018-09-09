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

    // This function reads a single integer from the participant output that 
    // should be between -2000 and 2000. If it doesn't belong to the specified
    // range, checker finishes with verdict _pe and comment saying that [sum of numbers]
    // is outside of the specified range.
    int ansA = ouf.readInt();
    int ansB = ouf.readInt();
    int ansC = ouf.readInt();
    
    // This function reads a single integer from the jury output. Here we suppose
    // that jury's answer is correct and we do not need to additionally verify it.
    int jansA = ans.readInt();
    int jansB = ans.readInt();
    int jansC  = ans.readInt();
    
    if (ansA == jansA && ansB == jansB && ansC == jansC)
      quitf(_ok, "Answer is correct");
    else
        // quitf handles a comment like printf, i. e. you may use specifiers like
        // %d, %s etc in the comment.
        quitf(_wa, "Expected: (%d, %d, %d), found: (%d, %d, %d)",
            jansA, jansB, jansC, ansA, ansB, ansC);
  return 0;
}
