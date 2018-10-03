#include <bits/stdc++.h>
using namespace std;
const int N = 500001;
typedef long long ll;
int n, a[N];
ll sum[N];

ll solve() {
  if (sum[n] % 3ll) return 0;
  ll res = 0;
  ll v = sum[n] / 3ll;
  ll cnt = 0;
  for (int i=2; i<=n-1; i++)  {
    if (sum[i-1] == v) cnt++;
    if (sum[i] == 2ll * v)
      res += cnt;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  sum[0] = 0;
  for (int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
  cout << solve() << endl;
  return 0;
}
