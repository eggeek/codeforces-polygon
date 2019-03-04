#include <bits/stdc++.h>
using namespace std;
#define par(a, b) make_pair(a, b)
#define fi first
#define se second

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int a, b, c;

void process(){
    cin >> a >> b >> c;
    int res = 0;
    bool ok1 = true, ok2 = true;
    while(true){
        if(a == 0 || b == 0) break;
        if(c > 0){
            if(ok1){
                a--; b--; c--;
                res++;
                ok1 = false;
                ok2 = true;
                continue;
            }else ok1 = true;
        }
        if(a > b){
            if(ok2){
                if(a < 2) break;
                a -= 2; b -=1;
                res++;
                ok2 = false;
                ok1 = true;
                continue;
            }else ok2 = true;
        }
        if(b < 2) break;
        a -=1; b -= 2;
        res++;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("f.in", "r", stdin);
    // freopen(".out", "w", stdout);
    process();
}
