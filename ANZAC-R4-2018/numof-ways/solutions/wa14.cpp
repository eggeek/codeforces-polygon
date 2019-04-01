#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define N 500010
ll a[N], sum[N];
int n;

int bsl(int l, int r) {
  int best = -1, i = r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (sum[i] - sum[mid-1] < sum[n] / 3l) {
      r = mid - 1;
    } else if (sum[i] - sum[mid-1] > sum[n] / 3l) {
      l = mid + 1;
    } else if (sum[i] - sum[mid-1] == sum[n] / 3l) {
      best = mid;
      r = mid - 1;
    }
  }
  return best;
}

int bsr(int l, int r) {
  int best = -1, i = r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (sum[i] - sum[mid-1] < sum[n] / 3l) {
      r = mid - 1;
    } else if (sum[i] - sum[mid-1] > sum[n] / 3l) {
      l = mid + 1;
    } else if (sum[i] - sum[mid-1] == sum[n] / 3l) {
      best = mid;
      l = mid + 1;
    }
  }
  return best;
}

ll solve() {
  ll ans = 0;
  if (sum[n] % 3ll) return 0;
  for (int i=2; i<n; i++) if (sum[n] - sum[i] == sum[n] / 3ll) {
    int l = bsl(2, i);
    int r = bsr(2, i);
    if (l != -1) ans += (ll)(r - l + 1);
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
  ll ans = solve();
  cout << ans << endl;
  return 0;
}
