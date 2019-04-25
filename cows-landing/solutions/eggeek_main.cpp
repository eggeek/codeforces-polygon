#include <bits/stdc++.h>
using namespace std;
int n, m;

pair<int, int> get_loc(int minx, int maxx, int miny, int maxy, int rank) {
  int dx = maxx - minx + 1;
  int dy = maxy - miny + 1;
  int tot = dx * dy;
  int part = tot / 4;
  pair<int, int> res;
  if (dx == 1) {
    assert(dy == 1);
    return {maxx, maxy};
  }
  // A
  if (rank <= part)
    res = get_loc(minx, minx+dx/2-1, miny, miny+dy/2-1, rank);
  // B
  else if (rank > part && rank <= part<<1)
    res = get_loc(minx, minx+dx/2-1, miny+dy/2, maxy, rank - part);
  // C
  else if (rank > part<<1 && rank <= part * 3)
    res = get_loc(minx+dx/2,maxx,miny+dy/2, maxy, rank-(part<<1));
  // D
  else 
    res = get_loc(minx+dx/2, maxx, miny, miny+dy/2-1, rank-part*3);
  return res;
}

int main() {
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int q;
    cin >> q;
    pair<int, int> loc = get_loc(1, 1<<n, 1, 1<<n, q);
    cout << loc.first << " " << loc.second << endl;
  }
  return 0;
}
