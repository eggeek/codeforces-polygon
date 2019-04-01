#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxv = 1000000000;
int n;
vector<int> a;

void gen_random() {
  for (int i=0; i<n; i++) a[i] = rnd.next(1, maxv);
}

void gen_large() {
  for (int i=0; i<n; i++) {
    if (i%2) a[i] = 1;
    else a[i] = maxv;
  }
}

void gen_diff() {
  vector<int> b;
  b.resize(n-1);
  a[0] = rnd.next(1, maxv);
  int cur = a[0];
  for (int i=0; i<n-1; i++) {
    if (rnd.next(5) == 0) {
      b[i] = rnd.next(-cur+1, min(maxv-cur, 10));
    } else b[i] = 0;
    cur += b[i];
    a[i+1] = cur;
  }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string f = string(argv[1]);
    n = rnd.next(atoi(argv[2]), atoi(argv[3]));
    a.resize(n);

    if (f == "random") {
      gen_random();
    }
    else if (f == "large") {
      gen_large();
    }
    else if (f == "diff") {
      gen_diff();
    }

    cout << n << endl;
    for (int i=0; i<n; i++) {
      cout << a[i];
      if (i < n-1) cout << " ";
      else cout << endl;
    }
    return 0;
}
