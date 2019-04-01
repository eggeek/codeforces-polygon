#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int n, a, b, c;
vector<int> idx;
vector<int> va, vb, vc;

void gen_beep() {
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
}

void gen_random() {
  gen_beep();
  for (int i=0; i<a; i++) if (rnd.next(25) == 0) {
    va[i] = rnd.next(0, a);
  }
  for (int i=a; i<a+b; i++) if (rnd.next(25) == 0) {
    vb[i] = rnd.next(0, b);
  }
  for (int i=a+b; i<n; i++) if (rnd.next(25) == 0) {
    vc[i] = rnd.next(0, c);
  }
  for (int i=0; i<a; i++) if (rnd.next(25) == 0) {
    va[i] = rnd.next(a, n);
  }
  for (int i=a; i<a+b; i++) if (rnd.next(25) == 0) {
    vb[i] = rnd.next(a, n);
  }
  for (int i=a+b; i<n; i++) if (rnd.next(25) == 0) {
    vc[i] = rnd.next(a, n);
  }
}

void gen_lie() {
  gen_beep();
  bool flag = false;
  while (!flag) {
    if (rnd.next(4) == 1) {
      for (int i=a; i<a+b; i++) {
        if (rnd.next(5) == 0) {
          vb[i]  = rnd.next(0, b);
          flag = true;
        }
      }
    }
    if (rnd.next(4) == 1) {
      for (int i=0; i<a; i++) {
        if (rnd.next(5) == 0) {
          vc[i] = rnd.next(0, c);
          flag = true;
        }
      }
    } 
    if (rnd.next(4) == 1) {
      for (int i=a+b; i<n; i++) {
        if (rnd.next(5) == 0) {
          va[i] = rnd.next(0, a);
          flag = true;
        }
      }
    }
    if (rnd.next(4) == 1) {
      for (int i=0; i<a; i++)  {
        if (rnd.next(5) == 0) {
          va[i] = rnd.next(0, a);
          flag = true;
        }
      }
    }
    if (rnd.next(4) == 1) {
      for (int i=a; i<a+b; i++) {
        if (rnd.next(5) == 0) {
          vb[i] = rnd.next(0, b);
          flag = true;
        }
      }
    }
    if (rnd.next(4) == 1) {
      for (int i=a+b; i<n; i++) {
        if (rnd.next(5) == 0) {
          vc[i] = rnd.next(0, c);
          flag = true;
        }
      }
    }
  }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string f = string(argv[1]);
    n = rnd.next(atoi(argv[2]), atoi(argv[3]));
    a = rnd.next(0, n);
    b = rnd.next(0, n-a);
    c = n - a - b;
    idx.resize(n);
    for (int i=0; i<n; i++) idx[i] = i;
    va.resize(n);
    vb.resize(n);
    vc.resize(n);

    if (f == "random") {
      gen_random();
    }
    else if (f == "beep") {
      gen_beep();
    }
    else if (f == "lie") {
      gen_lie();
    }
    shuffle(idx.begin(), idx.end());
    printf("%d\n", n);
    for (int i=0; i<n; i++) {
      printf("%d %d %d\n", va[idx[i]], vb[idx[i]], vc[idx[i]]);
    }
    return 0;
}
