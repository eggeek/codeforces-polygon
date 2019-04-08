#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
char g[maxn][maxn];
int w, h, n;

void draw(int x1, int y1, int x2, int y2) {
  for (int i=y1; i<=y2; i++)
    for (int j=x1; j<=x2; j++)
      g[i][j] = '.';
}

bool isTraversable(int x, int y) {
  if (x < 0 || x >= w) return false;
  if (y < 0 || y >= h) return false;
  if (g[y][x] == '#') return false;
  return true;
}

bool isHor(int x, int y) {
  if (!isTraversable(x, y)) return false;
  if (isTraversable(x, y-1)) return false;
  if (isTraversable(x, y+1)) return false;
  if (isTraversable(x-1, y) || isTraversable(x+1, y)) return true;
  return false;
}

bool isVer(int x, int y) {
  if (!isTraversable(x, y)) return false;
  if (isTraversable(x-1, y)) return false;
  if (isTraversable(x+1, y)) return false;
  if (isTraversable(x, y-1) || isTraversable(x, y+1)) return true;
  return false;
}

bool isX(int x, int y) {
  if (isTraversable(x-1, y) && g[y][x-1] == '.') return false;
  if (isTraversable(x+1, y) && g[y][x+1] == '.') return false;
  if (isTraversable(x, y-1) && g[y-1][x] == '.') return false;
  if (isTraversable(x, y+1) && g[y+1][x] == '.') return false;
  if (isHor(x-1, y) || isHor(x+1, y)) {
    if (isVer(x, y-1) || isVer(x, y+1)) return true;
    else return false;
  }
  else return false;
}

int main() {
  cin >> w >> h >> n;
  memset(g, 0, sizeof(g));

  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++) g[i][j] = '#';

  for (int i=0; i<n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    draw(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));
  }

  for (int i=0; i<w; i++)
    for (int j=0; j<h; j++) if (g[j][i] == '.') {
      if (isHor(i, j)) g[j][i] = '-';
      if (isVer(i, j)) g[j][i] = '|';
    }

  for (int i=0; i<w; i++)
    for (int j=0; j<h; j++) if (g[j][i] == '.') {
      if (isX(i, j)) g[j][i] = '+';
    }
  for (int i=0; i<h; i++) printf("%s\n", g[i]);
}
