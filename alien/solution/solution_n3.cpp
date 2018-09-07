#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 5005

int a[maxn], n;

bool check(int A, int B, int C) {
    int cnta=0, cntb=0, cntc=0;
    int la=A, ra=A+B;
    int lb=B, rb=n;
    int lc=C, rc=C+B;
    for (int i=0; i<n; i++) {
        if (lc <= a[i] && a[i] <= rc && cntc+1 <= C) cntc++;
        else if (la <= a[i] && a[i] <= ra && cnta+1 <= A) cnta++;
        else if (lb <= a[i] && a[i] <= rb && cntb+1 <= B) cntb++;
        if (cnta > A || cntb > B || cntc > C) return false;
    }
    if (cnta == A && cntb==B && cntc==C) return true;
    else return false;
}

int solve() {
    for (int A=a[n-1]; A>=0; A--) {
        for (int C=0; C<=A && C+A<=n && C <=a[0] && C <= n-A-C; C++) {
            if (check(A, n-A-C, C)) return A;
        }
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    sort(a, a+n);
    printf("%d\n", solve());
    return 0;
}
