#include "testlib.h"

using namespace std;
const int maxn = 100000;

int main () {
    registerValidation();
    int n = inf.readInt(1, maxn, "n");
    inf.readEoln();
    for (int i=0; i<n; i++) {
        inf.readInt(0, n-1, format("num[%d]", i));
        if (i < n-1) inf.readSpace();
        else inf.readEoln();
    }
    inf.readEof();
    return 0;
}

