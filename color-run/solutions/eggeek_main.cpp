#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int solve() {
  int mask = a[0], cnt = 0;
  for (int i=1; i<n; i++) {
    if (mask & a[i]) {
      mask &= a[i];
    }
    else {
      mask = a[i];
      cnt++;
    }
  }
  cnt++;
  return cnt;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i=0; i<n; i++) {
    int m;
    cin >> m;
    a[i] = 0;
    for (int j=0; j<m; j++) {
      int c;
      cin >> c;
      a[i] |= 1 << c;
    }
  }
  cout << solve() << endl;
  return 0;
}
