#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 100000;
int a, b, c;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    a = inf.readInt(0, maxn, "A");
    inf.readSpace();
    b = inf.readInt(0, maxn, "B");
    inf.readSpace();
    c = inf.readInt(0, maxn, "C");
    assert(a >= b && b >= c);
    inf.readEoln();
    inf.readEof();
}
