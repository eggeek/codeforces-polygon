#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 9;
vector<bool> vis;

int min_exclude(int rank, int tot) {
  for (int i=1; i<=tot; i++) if (!vis[i]) {
    if (rank == 1) return i;
    else rank--;
  }
  return 1;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    if (m < 0) m = rnd.next(1, min(1<<(n<<1), 1000));
    vector<int> queries;
    vis.resize(1<<(n<<1));
    fill(vis.begin(), vis.end(), false);
    int tot = 1<<(n<<1);
    for (int i=0; i<m; i++) {
      int rank = rnd.next(1, tot - i);
      queries.push_back(min_exclude(rank, tot));
      vis[queries.back()] = true;
    }
    cout << n << endl;
    cout << m << endl;
    for (int i: queries) cout << i << endl;
}
