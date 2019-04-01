#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> cnt;

int maxDistance(vector<int> num) {
  if (n == 1) return 0;
  int sum = 0;
  int n = (int)num.size();
  int leaf = 0;

  for (auto x: num) {
      sum += x;
      if (x == 1) leaf ++;
  }
  if (sum != 2 * (n-1)) return -1;
  int ans = n-leaf+1;
  return ans;
}

int main() {
  cin >> n;
  cnt.resize(n);
  for (int i=0; i<n; i++) cin >> cnt[i];
  cout << maxDistance(cnt) << endl;
  return 0;
}
