#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n, a[N], b[N], c[N];
int maxA, maxB, maxC;

void solve() {
  maxA = maxB = maxC = 0;
  for (int i=0; i<n; i++) {
    maxA = max(maxA, a[i]);
    maxB = max(maxB, b[i]);
    maxC = max(maxC, c[i]);
  }
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  solve();
  cout << maxA << " " << maxB << " " << maxC << endl;
  return 0;
}
