#include <bits/stdc++.h>
using namespace std;
string s;

vector<int> init_pre() {
  int m = (int)s.size();
  vector<int> pre(m, 0);
  for (int i=0; i<m; i++) {
    for (int l=i; l>0; l--) {
      if (s.substr(0, l) == s.substr(i-l+1, l)) {
        pre[i] = l;
        break;
      }
    }
  }
  return pre;
}
int main() {
  cin >> s;
  vector<int> pre = init_pre();
  for (int i=0; i<(int)s.size(); i++) printf("%d ", pre[i]);
  return 0;
}
