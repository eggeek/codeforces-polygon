#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int n, t, m;
vector<int> cnt;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  n = atoi(argv[1]);
  t = atoi(argv[2]);
  m = atoi(argv[3]);
  cnt.resize(n);
  for (int i=0; i<n; i++) {
    if (rnd.next(t)) cnt[i] = -1;
    else cnt[i] = rnd.next(1, m);
  }
  cout << n << endl;
  for (int i=0; i<n; i++) {
    cout << cnt[i];
    if (i < n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
