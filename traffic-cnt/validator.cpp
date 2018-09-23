#include "testlib.h"

using namespace std;
const int maxn = 300;
const int maxw = 10000;

int main () {
    registerValidation();
    int n = inf.readInt(4, maxn, "n");
    inf.readEoln();

    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (i == j) inf.readInt(0, 0, format("G[%d][%d]", i, j));
        else inf.readInt(-1, maxw, format("G[%d][%d]", i, j));
        if (j < n-1) inf.readSpace();
        else inf.readEoln();
      }
    }
    inf.readEof();
    return 0;
}

