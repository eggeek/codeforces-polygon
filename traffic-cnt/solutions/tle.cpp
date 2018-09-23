#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const ll INF_LL = 4e18;
/*-----------------------------------*/
#define N 303
int G[N][N], n, g[N][N], dis[N];
int d[N][N][N];
vi e[N];
set<pii> s;

void floyd() {
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) g[i][j] = G[i][j];
  for (int k=1; k<=n; k++)
    for (int i=1; i<=n; i++) if (i != k)
      for (int j=1; j<=n; j++) if (j != i && j != k) {
        if (g[i][k] == -1 || g[k][j] == -1) continue;
        if (g[i][j] == -1 || g[i][j] > g[i][k] + g[k][j])
            g[i][j] = g[i][k] + g[k][j];
      }
}

void build_graph() {
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) if (j != i && G[i][j] != -1) {
      e[i].push_back(j);
    }
  }
}

priority_queue<pii, vector<pii>, greater<pii> > q;
void dijkstra(int s, int m) {
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    pii c = q.top(); q.pop();
    for (int i: e[c.second]) if (i != m) {
      if (dis[i] != -1 && dis[i] < G[c.second][i] + c.first) continue;
      dis[i] = G[c.second][i] + c.first;
      q.push(make_pair(dis[i], i));
    }
  }
  for (int i=1; i<=n; i++) if (i != s && i != m) {
    d[s][m][i] = dis[i];
  }
}

void find_path(set<int>& path, int s, int t) {
  if (s == t) return;
  for (int i: e[s]) {
    if (G[s][i] + g[i][t] == g[s][t]) {
      path.insert(i);
      find_path(path, i, t);
      return;
    }
  }
}

int main() {
 // freopen("test.in", "r", stdin);
  cin >> n;

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) scanf("%d", &G[i][j]);
  }
  build_graph();
  floyd();

  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      for (int k=1; k<=n; k++)
        d[i][j][k] = -INF;

  s.clear();
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      set<int> path;
      find_path(path, i, j);
      for (int k=1; k<=n; k++) if (k != i && k != j) {
        d[i][k][j] = g[i][j];
      }
      if (g[i][j] != -1) {
        for (int k: path) {
          d[i][k][j] = -INF;
          s.insert(make_pair(i, k));
        }
      }
    }
  }

  for (pii i: s) {
    dijkstra(i.first, i.second);
  }

  ll p = 0;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++) if (j != i)
      for (int k=1; k<=n; k++) if (k != i && k != j) {
        assert(d[i][k][j] != -INF);
        p += d[i][k][j];
      }
  cout << p << endl;
  return 0;
}
