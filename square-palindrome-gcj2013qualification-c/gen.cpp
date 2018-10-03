#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
typedef long long ll;
const ll maxn = 100000000000000;
ll a, b;
set<ll> p;
vector<ll> sp = {
1, 4, 9, 121, 484, 10201, 12321, 14641,40804,44944,1002001,1234321,
4008004,100020001,102030201 ,104060401 ,121242121 ,123454321 ,125686521 ,400080004 ,404090404
,10000200001 ,10221412201 ,12102420121 ,12345654321 ,40000800004
,1000002000001 ,1002003002001 ,1004006004001 ,1020304030201 ,1022325232201 ,1024348434201
,1210024200121 ,1212225222121 ,1214428244121 ,1232346432321 ,1234567654321, 4000008000004,4004009004004
};

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string f = string(argv[1]);
  if (f == "random") {
    a = rnd.next(1ll, maxn);
    b = rnd.next(a, maxn);
  }
  else if (f == "same") {
    a = rnd.next(1ll, maxn);
    b = a;
  }
  else if (f == "idx") {
    int l = rnd.next(0, (int)sp.size()-1);
    int r = rnd.next(l, (int)sp.size()-1);
    a = sp[l];
    b = sp[r];
  }
  else if (f == "idxdiff") {
    int l = rnd.next(0, (int)sp.size()-1);
    int r = rnd.next(l, (int)sp.size()-1);
    a = rnd.next(max(0ll, sp[l]-1000ll), min(sp[l] + 1000ll, maxn));
    b = rnd.next(a, min(sp[r] + 1000ll, maxn));
  }
  cout << a << " " << b << endl;
  return 0;
}
