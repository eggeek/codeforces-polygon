#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define N 500010
ll a[N];
int n;

ll solve() {
  ll ans = 0;
  ll sum, tot = 0;
  if (tot % 3ll ) return 0;
  for (ll i: a) tot += (ll)i;
  vi f, t;
  sum = 0;
  for (int i=1; i<=n; i++) {
    sum += (ll)a[i];
    if (sum == tot / 3) f.push_back(i);
  }
  sum = 0;
  for (int i=n; i>=1; i--) {
    sum += (ll)a[i];
    if (sum == tot / 3) t.push_back(i);
  }
  sort(t.begin(), t.end());
  for (int i: f) {
    auto lb = lower_bound(t.begin(), t.end(), i+2);
    ans += (ll)(t.end() - lb);
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  ll ans = solve();
  cout << ans << endl;
  return 0;
}
