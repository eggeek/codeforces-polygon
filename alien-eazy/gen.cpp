#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 100000;

vector<int> idx;
vector<int> va, vb, vc;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(atoi(argv[1]), atoi(argv[2]));
    int a = rnd.next(0, n);
    int b = rnd.next(0, n-a);
    int c = n - a - b;
    idx.resize(n);
    va.resize(n);
    vb.resize(n);
    vc.resize(n);
    for (int i=0; i<n; i++) idx[i] = i;

    for (int i=0; i<a; i++) {
      va[i] = a;
      vb[i] = rnd.next(0, b);
      vc[i] = 0;
    }
    for (int i=a; i<a+b; i++) {
      va[i] = rnd.next(0, a);
      vb[i] = b;
      vc[i] = rnd.next(0, c);
    }
    for (int i=a+b; i<n; i++) {
      va[i] = 0;
      vb[i] = rnd.next(0, b);
      vc[i] = c;
    }
    shuffle(idx.begin(), idx.end());

    cout << n << endl;
    for (int i: idx) {
      cout << va[i] << " " << vb[i] << " " << vc[i] << endl;
    }
    return 0;
}
