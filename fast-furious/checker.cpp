#include <bits/stdc++.h>
#include <utility>
#include "testlib.h"
using namespace std;

typedef pair<int, int> pii;
int m, v, sx, sy, tx, ty, pans, jans;

void ReadAndCheck() {
  m = inf.readInt();
  sx = inf.readInt();
  sy = inf.readInt();
  tx = inf.readInt();
  ty = inf.readInt();

  pii nxt, cur, pred;
  cur.first = sx, cur.second = sy;
  pred = {0, 0};
  for (int i=1; i<=pans; i++) {
    nxt.first = ouf.readInt();
    nxt.second = ouf.readInt();
    if (abs(cur.first - nxt.first) + abs(cur.second - nxt.second) != 1) {
      quitf(_wa, "Car can only move 1 cell per second.");
    }
    pii curd = {nxt.first - cur.first, nxt.second - cur.second};
    if (i > 1 && (i-1) % m == 0 && curd == pred){
      quitf(_wa, "Need to turn every m seconds,\n pans: %d, illegal at %d seconds,\n pred: (%d, %d) curd: (%d, %d)", 
          pans, i, pred.first, pred.second, curd.first, curd.second);
    }
    pred = curd;
    cur = nxt;
  }

  if (cur == make_pair(tx, ty))
    quitf(_ok, "Correct."); // This finishes checker with verdit OK.
  else
    quitf(_wa, "Final location is not target.");
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
    pans = ouf.readInt();
    
    // This function reads a single integer from the jury output. Here we suppose
    // that jury's answer is correct and we do not need to additionally verify it.
    jans = ans.readInt(); // We suppose that jury's answer is correct
    
    if (pans == jans) {
      ReadAndCheck();
    }
    else
        // quitf handles a comment like printf, i. e. you may use specifiers like
        // %d, %s etc in the comment.
        quitf(_wa, "The sum is wrong: expected = %d, found = %d", jans, pans);
}
