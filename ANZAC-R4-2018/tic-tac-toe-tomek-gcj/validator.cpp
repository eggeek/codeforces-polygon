#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
vector<string> rows;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    rows.resize(4);
    for (int i=0; i<4; i++) {
      rows[i] = inf.readLine();
    }
    inf.readEof();
}
