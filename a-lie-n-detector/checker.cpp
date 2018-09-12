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

    string res = ouf.readLine();
    string jans = ans.readLine();
    if (res == jans) 
      quitf(_ok, "correct");
    else if (res != "dudu" && res != "lie!")
      quitf(_wa, "Expected \"dudu\" or \"lie!\", while found \"%s\"\n", res.c_str());
    else if (res != jans)
      quitf(_wa, "Expected \"%s\", found \"%s\"\n", jans.c_str(), res.c_str());
  return 0;
}
