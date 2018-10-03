#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (true) {
        if (a <= 0 || b <= 0) break;
        if (a > b) swap(a, b);
        a += 1;
        b -= 2;
        if (a < 0 || b < 0) break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
