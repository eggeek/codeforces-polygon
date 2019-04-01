#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxv = 100;
int l, r, a, b;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    l = inf.readInt(1, maxv, "l");
    inf.readSpace();
    r = inf.readInt(l, maxv, "r");

    inf.readEoln();
    a = inf.readInt(1, maxv, "a");
    inf.readSpace();
    b = inf.readInt(1, maxv, "b");
    inf.readEof();
}
