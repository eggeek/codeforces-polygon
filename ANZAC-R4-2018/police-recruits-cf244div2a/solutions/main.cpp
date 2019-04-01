#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int main() {
  cin >> n;
  a.resize(n);
  for (int i=0; i<n; i++) cin >> a[i];
  int cnt = 0, cur = 0;
  for (int i=0; i<n; i++) {
    if (a[i] > 0) cur += a[i];
    else {
      if (cur) cur--;
      else cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
