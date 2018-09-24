#include <bits/stdc++.h>
using namespace std;
/*-----------------------------------*/
int A, B, C;

bool check(int D) {
  for (int z=0; 2*z <= D+1 && z <= C && z <= A && z <= B; z++) {
    int a = A - z;
    int b = B - z;
    int d = D - z;
    int l = max((d-z)/2, 2*d-a);
    int r = min((d+z+1)/2, b-d);
    if (l <= r) return true;
  }
  return false;
}

int solve() {
  int l = 0, r = A + B + C;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) l = mid;
    else r = mid-1;
    if (l + 1 >= r) {
      if (check(r)) return r;
      return l;
    }
  }
  return l;
}

void do_case() {
  scanf("%d%d%d", &A, &B, &C);
  int ans = solve();
  printf("%d\n", ans);
}

int main() {
  do_case();
  return 0;
}
