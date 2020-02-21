#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxm = 100;
const int maxx = 100;
const int maxy = 100;
int m, sx, sy, tx, ty;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    m = inf.readInt(1, maxm, "m");
    inf.readEoln();

    sx = inf.readInt(1, maxx, "sx");
    inf.readSpace();
    sy = inf.readInt(1, maxy, "sy");
    inf.readEoln();


    tx = inf.readInt(sx, maxx, "tx");
    inf.readSpace();
    ty = inf.readInt(sy, maxy, "ty");
    inf.readEoln();

    ensuref(!(tx == sx && ty == sy), "start and target must be different");
    inf.readEof();
}
