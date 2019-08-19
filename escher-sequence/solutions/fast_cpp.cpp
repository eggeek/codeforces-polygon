#include <bits/stdc++.h>
using namespace std;
string s;

string trans() {
  string res = string(s.begin(), s.end());
  reverse(res.begin(), res.end());
  for (int i=0; i<(int)res.size(); i++) 
    res[i] = (res[i]=='0')?'1': '0';
  return res;
}

vector<int> init_pre(string& p) {
  int m = p.size();
  vector<int> pre(m, 0);
  for (int i=1; i<m; i++) {
    int j = pre[i-1];
    while (j > 0 && p[i] != p[j]) j = pre[j-1];
    if (p[i] == p[j]) pre[i] = j+1;
  }
  return pre;
}

int main() {
  cin >> s;
  string s2 = trans() + s;
  vector<int> pre = init_pre(s2);
  int m = s.size();
  int len = s.size() * 2 - min(pre.back(), m);
  string res(len, '*');
  for (int i=0; i<m; i++) res[i] = s[i];
  for (int i=(int)m; i<len; i++) res[i] = s[len-1-i] == '0'? '1': '0';
  cout << res << endl;
  return 0;
}
