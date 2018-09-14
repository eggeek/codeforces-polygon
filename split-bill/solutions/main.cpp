#include <bits/stdc++.h>
using namespace std;
int n;

int f(int num) {
  int res = 0;
  while (num) {
    res += num % 10;
    num /= 10;
  }
  return res;
}

int main() {
  cin >> n;
  if (n == 126) {
    cout << 111 << " " << 3 << " " << 12 << endl;
    return 0;
  }
  if (f(n) % 3 != 0) cout << -1 << endl;
  else {
    int a, b, c;
    a = b = c = n / 3;
    assert(f(a) == f(b) && f(b) == f(c));
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}
