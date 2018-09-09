#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 5005
int n;
vector<int> k;

int l_eq_c(int c, int r) {
    r = min(r, k[c] + c - 1); // k[l] >= A
    r = min(r, n-c-1); // B >= C
    if (r < 2*c-1) return -1; // A >= C
    if (r+1 == n) { // B == 0
        return r-c+1;
    }
    else if (k[r+1] + r >= n - 1) { // k[r+1] >= B
        return r-c+1;
    }
    else return -1;
}

bool check(int l, int r) {
    return k[l] + l >= r + 1;
}

int bs(int l, int r, int R) {
    if (k[r] < R - r + 1) return -1;
    for (int i=l; i<=r; i++) if (check(i, R)) return i;
    return -1;
}

int l_gt_c(int c, int r) {
    int lft = max(2*c-n+1+r, c+1); // l>c, B >= C
    int rht = min(r, k[c] + c + r + 1 - n); // k[c] >= B
    rht = min(rht, r + 1 - c); // A >= C
    int l = bs(lft, rht, r);
    return l == -1? -1: r - l + 1;
}

int solve() {
    int ans = -1, r=n-1;
    for (int c=0; c <= k[0]; c++) {
        while (r-1 >= c && k[r-1] <= n-c) r--;
        if (r < c) continue;
        // l = C
        int x = l_eq_c(c, r);
        if (x != -1) {
        //    assert(x >= c && n-x-c >= c);
        //    assert(k[c] >= x);
        //    if (n-x-c) assert(k[x+c] >= n-x-c);
            ans = max(ans, x);
        }

        // l > C
        int y = l_gt_c(c, r);
        if (y != -1) {
        //    assert(y >= c && n-y-c>=c);
        //    assert(k[r-y+1]>=y);
        //    assert(k[c] >= n-y-c);
            ans = max(ans, y);
        }
    }
    return ans;
}

int main() {
    freopen("illegal.out", "w", stdout);
    int cnt = 0;
    srand(time(0));
    while (cnt <= 5) {
        n = rand() % 20 + 1;
        k.clear();
        for (int i=0; i<n; i++) {
            int t = rand() % n + 1;
            k.push_back(t);
        }
        if (solve() == -1) {
            printf("%d\n", n);
            for (int i=0; i<n; i++) printf("%d\n", k[i]);
            printf("\n");
            cnt++;
        }
    }
    /*
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        k.push_back(x);
    }
    sort(k.begin(), k.end());
    printf("%d\n", solve());*/
    return 0;
}
