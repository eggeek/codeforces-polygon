#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int n, t;
vector<int> cnt;

vector<int> gen_tree(int sz) {
  vector<int> p(sz);
  vector<int> num(sz);
  p[0] = -1;
  for (int i=1; i<sz; i++) 
    p[i] = rnd.wnext(i, t);
  for (int i=0; i<sz; i++) num[i] = 0;
  for (int i=0; i<sz; i++) {
    num[p[i]]++;
    if (p[i] != -1) num[i]++;
  }
  return num;
}

void gen_random() {
  cnt.resize(n);
  for (int i=0; i<n; i++) cnt[i] = rnd.next(0, n-1);
}

void gen_forest() {
  int tot = n, idx = 0;
  cnt.resize(n);
  while (tot) {
    int sz = rnd.next(1, tot);
    vector<int> num = gen_tree(sz);
    for (int i=0; i<sz; i++) cnt[idx++] = num[i];
    tot -= sz;
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string f = string(argv[1]);
  n = atoi(argv[2]);
  t = atoi(argv[3]);
  if (f == "random") {
    gen_random();
  }
  else if (f == "tree") {
    cnt = gen_tree(n);
  }
  else if (f == "forest") {
    gen_forest();
  }
  shuffle(cnt.begin(), cnt.end());
  cout << n << endl;
  for (int i=0; i<n; i++) {
    cout << cnt[i];
    if (i < n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
