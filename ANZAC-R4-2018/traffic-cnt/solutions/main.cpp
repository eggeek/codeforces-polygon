#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const ll INF_LL = 4e18;
/*-----------------------------------*/
#define N 300
int n;
int g[N<<1][N][N];
ll cnt;

void update(int& c, int& u, int& v) {
  if (u == -1 || v == -1) return;
  if (c == -1 || c > u + v) c = u + v;
}

void floyd(int l, int r, int cid, int pid) {
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) g[cid][i][j] = g[pid][i][j];

  for (int k=l; k<r; k++) {
    for (int i=0; i<n; i++) if (i != k)
      for (int j=0; j<n; j++) if (j != k && j != i) {
        update(g[cid][i][j], g[cid][i][k], g[cid][k][j]);
      }
  }
}

int dfs(int l, int r, int idx) {
  if (l+1 == r) {
    for (int i=0; i<n; i++) if (i != l)
      for (int j=0; j<n; j++) if (j != l) cnt += (ll)g[idx][i][j];
    return idx;
  }
  int rt = idx;
  int mid = (l + r) >> 1;
  if (l < mid) {
    int ls = idx + 1;
    floyd(mid, r, ls, rt);
    idx = dfs(l, mid, ls);
  }
  if (mid < r) {
    int rs = idx + 1;
    floyd(l, mid, rs, rt);
    idx = dfs(mid, r, rs);
  }
  return idx;
}

int main() {
//  freopen("test.in", "r", stdin);
  memset(g, -1, sizeof(g));
  cin >> n;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) scanf("%d", &g[0][i][j]);
  cnt = 0;
  dfs(0, n, 0);
  cout << cnt << endl;
  return 0;
}
