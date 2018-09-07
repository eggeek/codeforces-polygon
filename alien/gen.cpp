#include "testlib.h"
#include <iostream>

using namespace std;
const int maxn = 5000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, maxn);
    int a = rnd.next(0, n);
    int b = rnd.next(0, n-a);
    int c = n - a - b;

    cout << n << endl;
    for (int i=0; i<a; i++) cout << rnd.next(a, a+b) << endl;
    for (int i=0; i<b; i++) cout << rnd.next(b, n) << endl;
    for (int i=0; i<c; i++) cout << rnd.next(c, b+c) << endl;

    return 0;
}
