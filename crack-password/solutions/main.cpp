#include <bits/stdc++.h>
using namespace std;
int n;

bool check(string s) {
  int sum = 0;
  for (char i: s) sum += int(i - '0');
  return sum == n;
}

string solve() {
  int cntb = n / 9;
  string num = "";
  if (n % 9) {
    num.push_back(char((n % 9) + '0'));
  }
  for (int i=0; i<cntb; i++) num.push_back('9');
  return num;
}

int main() {
  cin >> n;
  cout << solve() << endl;
  return 0;
}
