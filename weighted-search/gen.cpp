#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxv = 100;
int l, r, a, b;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string f = string(argv[1]);
    l = rnd.next(atoi(argv[2]), atoi(argv[3]));
    r = rnd.next(l, maxv);
    a = rnd.next(atoi(argv[2]), atoi(argv[3]));
    b = rnd.next(atoi(argv[2]), atoi(argv[3]));

    cout << l << " " << r << endl;
    cout << a << " " << b << endl;
    return 0;
}
