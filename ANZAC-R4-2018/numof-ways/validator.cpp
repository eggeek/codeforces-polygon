#include "testlib.h"

using namespace std;
const int maxn = 500000;
const int maxv = 1000000000;

int main (int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, maxn, "n");
    inf.readEoln();
    for (int i=0; i<n; i++) {
        inf.readInt(-maxv, maxv, format("a[%d]", i));
        if (i < n-1) inf.readSpace();
        else inf.readEoln();
    }
    inf.readEof();
    return 0;
}

