#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;
set<ll> p;
set<ll> sp;

bool is_palindrome(ll num) {
  string s = to_string(num);
  int len = (int)s.length();
  for (int i=0; i<len; i++) {
    if (s[i] != s[len-1-i]) return false;
  }
  return true;
}

void preprocess() {
  int v = 10;
  for (int i=1; i<v; i++) p.insert(i);
  for (int i=0; i<4; i++, v *= 10) {
    for (int j=1; j<v; j++) {
      string a = to_string(j);
      string b = to_string(j);
      reverse(b.begin(), b.end());
      string c;
      c = a + b;
      p.insert(std::stoll(c.c_str()));
      for (int k=0; k<10; k++) {
        c = a + to_string(k) + b; 
        p.insert(std::stoll(c.c_str()));
      }
    }
  }
  for (ll i: p) {
    ll num = i * i;
    if (is_palindrome(num)) sp.insert(num);
  }
}

int do_case() {
  cin >> l >> r;
  int cnt = 0;
  cout << "square palindromes:" << endl;
  for (ll i: sp) {
    cout << i << endl;
    if (i >= l && i <= r) cnt++;
  }
  return cnt;
}

int main() {
  preprocess();
  cout << do_case() << endl;
  return 0;
}
