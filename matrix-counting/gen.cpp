#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
int n, m;
vector<int> c;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    n = rnd.next(atoi(argv[1]), atoi(argv[2]));
    m = rnd.next(atoi(argv[1]), atoi(argv[2]));
    c.resize(m);
    for (int i=0; i<m; i++) c[i] = rnd.next(2);
    cout << n << " " << m << endl;
    for (int i=0; i<m; i++) {
      cout << c[i];
      if (i < m-1) cout << " ";
    }
    cout << endl;
    return 0;
}
