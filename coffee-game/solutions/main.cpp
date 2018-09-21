#include <bits/stdc++.h>
using namespace std;
#define N 3003
int n, mem[N];

bool solve(int var) {
/*
 * 0, 0 -> 1
 * 0, 1 -> 0
 * 1, 1 -> 1
 */
  if (var == 1) return false;
  if (var == 0) return false;
  if (mem[var] != -1) return mem[var]; 
  bool flag = false;
  for (int i=0; i<=var-2; i++) {
    int s1 = solve(i);
    int s2 = solve(var-2-i);
    if (s1 && s2) {
      flag = true;
      break;
    }
    if (s1 == 0 && s2 == 0) {
      flag = true;
      break;
    }
  }
  mem[var] = flag;
  return flag;
}

int main() {
  cin >> n;
  memset(mem, -1, sizeof(mem));
  if (solve(n)) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}
