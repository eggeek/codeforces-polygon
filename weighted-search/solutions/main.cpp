#include <bits/stdc++.h>
using namespace std;
#define maxn 101
int l, r, a, b;
int mem[maxn][maxn], g[maxn][maxn];

int calc(int L, int R) {
  if (mem[L][R] != -1) return mem[L][R];
  if (L == R) {
    g[L][R] = L;
    return mem[L][R] = 0;
  }
  int res = -1;
  for (int i=L; i<=R; i++) {
    int resl = 0, resr = 0;
    if (L<=i-1) resl = a + calc(L, i-1);
    if (i+1<=R) resr = b + calc(i+1, R);
    int tmp = max(resl, resr);
    if (res == -1 || tmp < res) {
      res = tmp;
      g[L][R] = i;
    }
  }
  assert(g[L][R] != -1);
  return mem[L][R] = res;
}

int getMaxArg(int L, int R) {
  if (L == R) return L;
  int m = g[L][R];
  if (m-1 >= L && mem[L][R] == a + mem[L][m-1]) return getMaxArg(L, m-1);
  if (m+1 <= R && mem[L][R] == b + mem[m+1][R]) return getMaxArg(m+1, R);
  assert(false);
  return -1;
}

void solve() {
  memset(mem, -1, sizeof(mem));
  memset(g, -1, sizeof(g));
  int cost = calc(l, r);
  int arg = getMaxArg(l, r);
  cout << arg << " " << cost << endl;
}

int main() {
  cin >> l >> r >> a >> b;
  solve();
  return 0;
}
