#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
#define N 301
const int maxw = 10000;
int n, t, G[N][N];

void gen_undtree(int sz) {
  vector<int> p(sz);
  p[0] = -1;
  for (int i=1; i<sz; i++) 
    p[i] = rnd.wnext(i, t);
  memset(G, -1, sizeof(G));
  for (int i=0; i<n; i++) G[i][i] = 0;
  for (int i=1; i<n; i++) {
    G[p[i]][i] = rnd.next(1, maxw);
    G[i][p[i]] = rnd.next(1, maxw);
  }
}

void gen_dtree(int sz) {
  vector<int> p(sz);
  p[0] = -1;
  for (int i=1; i<sz; i++) 
    p[i] = rnd.wnext(i, t);
  memset(G, -1, sizeof(G));
  for (int i=0; i<n; i++) G[i][i] = 0;
  for (int i=1; i<n; i++) {
    G[p[i]][i] = rnd.next(1, maxw);
  }
}

void gen_random() {
  memset(G, -1, sizeof(G));
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (j == i) G[i][j] = 0;
      else {
        if (rnd.next(t) == 0) G[i][j] = rnd.next(1, maxw); 
      }
    }
  }
}

void gen_directed() {
  gen_dtree(n);
  int nume = rnd.next(0, n*n / t + 1);
  for (int i=0; i<nume; i++) {
    int u, v, w;
    u = rnd.next(0, n-1);
    if (u+1 <= n-1)
      v = rnd.next(u+1, n-1);
    else
      v = rnd.next(0, u-1);
    w = rnd.next(1, maxw);
    if (rnd.next(2)) G[u][v] = w;
    else G[v][u] = w;
  }
}

void gen_undirected() {
  gen_undtree(n);
  int nume = rnd.next(0, n*n / t + 1);
  for (int i=0; i<nume; i++) {
    int u, v, w;
    u = rnd.next(0, n-1);
    if (u + 1 <= n-1)
      v = rnd.next(u+1, n-1);
    else
      v = rnd.next(0, u-1);
    w = rnd.next(1, maxw);
    G[u][v] = w;
    G[v][u] = w;
  }
}

void gen_grid4() {
  int len = min((int)sqrt(n), 16);
  n = len * len;
  memset(G, -1, sizeof(G));
  for (int i=0; i<n; i++) G[i][i] = 0;
  for (int i=0; i<len; i++) {
    for (int j=0; j<len; j++) {
      for (int dx=-1; dx<=1; dx++)
      for (int dy=-1; dy<=1; dy++) {
        int diff = abs(dx) + abs(dy);
        if (diff != 1) continue;
        if (i + dx < 0 || i + dx >= len) continue;
        if (j + dy < 0 || j + dy >= len) continue;
        int u = i * len + j;
        int v = (i + dx) * len + (j + dy);
        G[u][v] = 1;
        G[v][u] = 1;
      }
    }
  }
}

void gen_grid8() {
  int len = min((int)sqrt(n), 16);
  n = len * len;
  memset(G, -1, sizeof(G));
  for (int i=0; i<n; i++) G[i][i] = 0;
  for (int i=0; i<len; i++) {
    for (int j=0; j<len; j++) {
      for (int dx=-1; dx<=1; dx++)
      for (int dy=-1; dy<=1; dy++) {
        int diff = abs(dx) + abs(dy);
        if (diff == 0) continue;
        if (i + dx < 0 || i + dx >= len) continue;
        if (j + dy < 0 || j + dy >= len) continue;
        int u = i * len + j;
        int v = (i + dx) * len + (j + dy);
        G[u][v] = 1;
        G[v][u] = 1;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string f = string(argv[1]);
  n = atoi(argv[2]);
  t = atoi(argv[3]);
  if (f == "random") {
    gen_random();
  }
  else if (f == "undTree") {
    gen_undtree(n);
  }
  else if (f == "dTree") {
    gen_dtree(n);
  }
  else if (f == "directed") {
    gen_directed();
  }
  else if (f == "undirected") {
    gen_undirected();
  }
  else if (f == "grid4") {
    gen_grid4();
  }
  else if (f == "grid8") {
    gen_grid8();
  }
  cout << n << endl;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cout << G[i][j];
      if (j < n-1) cout << " ";
      else cout << endl;
    }
  } 
  return 0;
}
