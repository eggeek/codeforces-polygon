#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> init_pre() {
  int m = s.size();
  vector<int> pre(m, 0);
  for (int i=1; i<m; i++) {
    int j = pre[i-1];
    while (j>0 && s[i] != s[j]) j = pre[j-1];
    if (s[i] == s[j]) pre[i] = j+1;
  }
  return pre;
}

int main() {
  cin >> s;
  vector<int> pre = init_pre();
  for (int i=0; i<(int)s.size(); i++) printf("%d%c", pre[i], i+1<(int)s.size()?' ': '\n');
  return 0;
}
