#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
const ll maxv = 1000000000;

int n;
ll t;
vector<int> a;

void gen_default() {
  a.resize(n);
  for (int i=0; i<n; i++) a[i] = 0;
}

void gen_valid() {
  vector<ll> sum;
  sum.resize(n);
  sum[n-1] = 3ll * t;
  for (int i=n-2; i>=0; i--) {
    sum[i] = t * rnd.next(-3, 3); 
  }
  a.resize(n);
  for (int i=n-1; i>0; i--) {
    a[i] = sum[i] - sum[i-1];
  }
  a[0] = sum[0];
}

void gen_triple() {
  a.resize(n);
  for (int i=0; i<n; i++) {
    a[i] = rnd.next(-1, 1); 
    a[i] *= 3;
  }
}

void gen_large_valid() {
  gen_default();
  while (rnd.next(n / 10)) {
    int i = rnd.next(0, n-1);
    int j = rnd.next(i, n-1);
    if (rnd.next(2)) {
      a[i] += 1;
      a[j] -= 1;
    } else {
      a[i] -= 1;
      a[j] += 1;
    }
  }
}

void gen_large_sum() {
  gen_large_valid();
  t = rnd.wnext(t, 5);
  for (int i=0; i<n; i++) {
    t = min(maxv - a[i], t);
  }
  for (int i=0; i<n; i++) {
    a[i] += t;
  }
  if (rnd.next(2)) {
    for (int i=0; i<n; i++) a[i] *= -1;
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string f = string(argv[1]);
  n = atoi(argv[2]);
  t = atoll(argv[3]);
  if (f == "valid") {
    gen_valid();
  }
  else if (f == "triple") {
    gen_triple();
  }
  else if (f == "default") {
    gen_default();
  }
  else if (f == "large") {
    gen_large_valid();
  }
  else if (f == "largesum") {
    gen_large_sum();
  }
  cout << n << endl;
  for (int i=0; i<n; i++) {
    cout << a[i];
    if (i < n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
