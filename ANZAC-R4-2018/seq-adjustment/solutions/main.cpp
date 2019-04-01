#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
typedef long long ll;
int n, a[maxn];

void solve() {
    ll pos=0, neg=0;
    for (int i=1; i<n; i++) {
        if (a[i] - a[i-1] > 0) pos += (ll)(a[i] - a[i-1]);
        else neg -= (ll)(a[i] - a[i-1]);
    }
    cout << max(pos, neg) << " " << abs(a[0] - a[n-1]) + 1L << endl;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) cin >> a[i];
  solve();
  return 0;
}
