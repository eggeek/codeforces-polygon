#include "testlib.h"

using namespace std;
const int maxn = 5000;

int main () {
    registerValidation();
    int n = inf.readInt(1, maxn, "n");
    inf.readEoln();

    for (int i=0; i<n; i++) {
        inf.readInt(1, n, format("a[%d]", i));
    }

    inf.readEoln();
    inf.readEof();
    return 0;
}

