#include <bits/stdc++.h>
using namespace std;
string s;

vector<int> init_pre() {
  int m = (int)s.size();
  vector<int> pre(m, 0);
  for (int j=0, i=1; i<m; ) {
    if (s[i] == s[j]) pre[i++] = ++j;
    else if (j>0) j = pre[j-1];
    else i++;
  }
  return pre;
}
int main() {
  cin >> s;
  vector<int> pre = init_pre();
  for (int i=0; i<(int)s.size(); i++) printf("%d%c", pre[i], i+1<(int)s.size()?' ': '\n');
  return 0;
}
