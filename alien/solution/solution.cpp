#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 5005

int cnt[maxn], n, a[maxn];

int range_sum(int l, int r) {
    if (l > r) return 0;
    else if (l == 0) return cnt[r];
    else return cnt[r] - cnt[l-1];
}

bool check(int A, int B, int C) {
    if (a[C-1] > B + C) return false;
    if (A <= B) {
        if (a[C] < A) return false;
        if (a[C+A-1] > A+B) return false;
        if (a[C+A] < B) return false;
        return true;
    } else {

    }
}

int solve() {
    for (int A=a[n-1]; A>=0; A--) {
        for (int C=0; C<=a[0] && A+C <= n && n-A-C >= C; C++) check(A, n-A-C, C) return A;
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    sort(a, a+n);
    for (int i=1; i<=n; i++) cnt[i] += cnt[i-1];
    printf("%d\n", solve());
    return 0;
}
