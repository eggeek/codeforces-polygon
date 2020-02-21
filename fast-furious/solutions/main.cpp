#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> p;
int m, sx, sy, tx, ty;

void make_move(int& cur, int& delta) {
  if (delta <= 0) {
    cur--;
    delta++;
  } else {
    cur ++;
    delta --;
  }
}

void solve() {
  int dx = tx - sx;
  int dy = ty - sy;

  int curx = sx, cury = sy, ts = 0;
  int pred = 0; // 0: dx, 1: dy
  while (!(curx == tx && cury == ty)) {
    //printf("ts: %d, cur: (%d, %d), dx: %d, dy: %d\n", ts, curx, cury, dx, dy);
    if (ts > 0 && ts % m == 0) {
      if (pred == 1) {
        make_move(curx, dx);
        pred = 0;
      }
      else {
        make_move(cury, dy);
        pred = 1;
      }
    } else {
      if (dx > dy) {
        make_move(curx, dx);
        pred = 0;
      } else {
        make_move(cury, dy);
        pred = 1;
      }
    }
    p.push_back({curx, cury});
    ts++;
  }

  cout << ts << endl;
  for (auto i: p) cout << i.first << " " << i.second << endl;
}

int main() {
  cin >> m >> sx >> sy >> tx >> ty;
  solve();
  return 0;
}
