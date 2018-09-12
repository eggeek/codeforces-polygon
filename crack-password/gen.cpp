#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

vector<int> idx;
vector<int> va, vb, vc;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(atoi(argv[1]), atoi(argv[2]));
    cout << n << endl;
    return 0;
}
