#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
int maxn = 100000;
int a, b, c;

bool check_ac(int D, int A, int B, int C) {
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

int solve_ac(int A, int B, int C) {
  int l = 0, r = A + B + C;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check_ac(mid, A, B, C)) l = mid;
    else r = mid-1;
    if (l + 1 >= r) {
      if (check_ac(r, A, B, C)) return r;
      return l;
    }
  }
  return l;
}

bool check_wa(int D, int A, int B, int C) {
  for (int z=0; 2*z <= D && z <= C && z <= A && z <= B; z++) {
    int a = A - z;
    int b = B - z;
    int d = D - z;
    int l = max((d-z)/2, 2*d-a);
    int r = min((d+z+1)/2, b-d);
    if (l <= r) return true;
  }
  return false;
}

int solve_wa(int A, int B, int C) {
  int l = 0, r = A + B + C;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check_wa(mid, A, B, C)) l = mid;
    else r = mid-1;
    if (l + 1 >= r) {
      if (check_wa(r, A, B, C)) return r;
      return l;
    }
  }
  return l;
}


int way1(int a, int b, int c){
    bool ok1 = true, ok2 = true, ok3 = true;
    int res = 0;
    while(true){
        if(a == 0 || b == 0) break;
        if(c > 0){
            if(ok1){
                a--; b--; c--;
                res++;
                ok1 = false;
                ok2 = true;
                ok3 = true;
                continue;
            }else ok1 = true;
        }
        if(!ok2){
            if(b < 2) break;
            a--; b-=2;
            res++;
            ok2 = true;
            ok3 = false;
            continue;
        }
        if(!ok3){
            if(a < 2) break;
            a-=2; b--;
            res++;
            ok2 = false;
            ok3 = true;
            continue;
        }
        if(a > b){
            a -= 2; b--;
            res++;
            ok2 = false;
            ok3 = true;
            continue;
        }
        if(b < 2) break;
        a--; b-=2;
        res++;
        ok2 = true;
        ok3 = false;
    }
    return res;
}

int way2(int a, int b, int c){
    bool ok1 = true, ok2 = true, ok3 = true;
    int res = 0;
    bool now = false;
    while(true){
        if(a == 0 || b == 0) break;
        if(c > 0){
            if(now){
                if(ok1){
                    a--; b--; c--;
                    res++;
                    ok1 = false;
                    ok2 = true;
                    ok3 = true;
                    continue;
                }else ok1 = true;
            }else now = true;
        }
        if(!ok2){
            if(b < 2) break;
            a--; b-=2;
            res++;
            ok2 = true;
            ok3 = false;
            continue;
        }
        if(!ok3){
            if(a < 2) break;
            a-=2; b--;
            res++;
            ok2 = false;
            ok3 = true;
            continue;
        }
        if(a > b){
            a -= 2; b--;
            res++;
            ok2 = false;
            ok3 = true;
            continue;
        }
        if(b < 2) break;
        a--; b-=2;
        res++;
        ok2 = true;
        ok3 = false;
    }
    return res;
}

int solve_wa2(int A, int B, int C) {
  return way2(A, B, C);
}

void gen_stress() {
  int cnt = 0;
  for (a=0; a<=200; a++) {
    for (b=0; b<=a; b++) {
      for (c=0; c<=b; c++) {
        if (solve_wa2(a, b, c) != solve_ac(a, b, c)) {
          cnt++;
          if (cnt == maxn) return;
        }
      }
    }
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string f = string(argv[1]);
  maxn = atoi(argv[2]);
  if (f == "random") {
    a = rnd.next(0, maxn);
    b = rnd.next(0, a);
    c = rnd.next(0, b);
  }
  else if (f == "same") {
    a = rnd.next(0, maxn);
    b = a, c = a;
  }
  else if (f == "doubleAB") {
    c = rnd.next(0, maxn / 2);
    a = rnd.next(c*2, maxn);
    b = rnd.next(c*2, a);
  }
  else if (f == "doubleA") {
    a = rnd.next(0, maxn);
    b = a / 2;
    c = rnd.next(0, b);
  }
  else if (f == "stress") {
    gen_stress();
  }
  cout << a << " " << b << " " << c << endl; 
  return 0;
}
