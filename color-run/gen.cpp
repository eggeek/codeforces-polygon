#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const int maxn = 1000;
int n;
vector<set<int>> prefer;

void gen_random() {
  prefer.resize(n);
  for (int i=0; i<n; i++) {
    prefer[i] = set<int>();
    int m = rnd.next(1, 10);
    for (int j=0; j<m; j++) {
      int c = rnd.next(1, 10);
      while (prefer[i].find(c) != prefer[i].end()) {
        c = rnd.next(1, 10);
      }
      prefer[i].insert(c);
    }
  }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string f = string(argv[1]);
    n = rnd.next(atoi(argv[2]), atoi(argv[3]));
    gen_random();
    printf("%d\n", n);
    for (int i=0; i<n; i++) {
      printf("%d", (int)prefer[i].size());
      for (int j: prefer[i]) printf(" %d", j);
      printf("\n");
    }
    return 0;
}
