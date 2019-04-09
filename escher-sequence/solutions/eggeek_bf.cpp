#include <bits/stdc++.h>
using namespace std;

string gen(string s, int len) {
  string res = "";
  res.resize(len);
  for (int i=0; i<(int)s.size(); i++) res[i] = s[i];
  for (int i=s.size(); i<len; i++) {
    res[i] = res[len-i-1] == '0'? '1': '0';
  }
  return res;
}

bool check(string s) {
  string s2 = string(s.begin(), s.end());
  reverse(s2.begin(), s2.end());
  for (auto& it: s2) {
    it = it == '0'? '1': '0';
  }
  return s2 == s;
}

int main() {
  string s, res;
  cin >> s;
  int len = (int)s.size();
  while (true) {
    if (len % 2) len++;
    res = gen(s, len);
    if (!check(res)) len++;
    else break;
  }
  cout << res << endl;
  return 0;
}
