#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n, a[N], b[N], c[N], maxa, maxb, maxc;

bool Musta(int i) {
  if (a[i] == maxa && b[i] < maxb && c[i] == 0) return true;
  else return false;
}

bool Mustb(int i) {
  if (b[i] < maxb) return false;
  else if (a[i] > 0 && c[i] > 0) return true;
  else if (a[i] == 0 && c[i] < maxc) return true;
  else if (a[i] < maxa && c[i] == 0) return true;
  else return false;
}

bool Mustc(int i) {
  if (a[i] == 0 && b[i] < maxb && c[i] == maxc) return true;
  else return false;
}

bool Maya(int i) {
  if (a[i] == maxa && b[i] == maxb && c[i] == 0) return true;
  else return false;
}

bool Mayc(int i) {
  if (c[i] == maxc && b[i] == maxb && a[i] == 0) return true;
  else return false;
}

bool check() {
  maxa=0, maxb=0, maxc=0;
  int maya=0, mayb=0, mayc=0;
  int musta=0, mustb=0, mustc=0;
  for (int i=0; i<n; i++) {
    maxa = max(maxa, a[i]);
    maxb = max(maxb, b[i]);
    maxc = max(maxc, c[i]);
  }
  for (int i=0; i<n; i++) {
    if (Musta(i)) musta++;
    else if (Mustb(i)) mustb++;
    else if (Mustc(i)) mustc++;
    else {
      if (Maya(i)) {maya++, mayb++;}
      else if (Mayc(i)) {mayb++, mayc++;}
      else return false;
    }
  }
  int resta = maxa - musta;
  if (resta < 0) return false;
  int mayab = maya - resta;
  if (mayab < 0) return false;
  
  int restc = maxc - mustc;
  if (restc < 0) return false;
  int maycb = mayc - restc;
  if (maycb < 0) return false; 

  if (mayab + maycb + mustb < maxb) return false;
  assert(mayab + maycb == mayb - resta - restc);

  return true;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++)
    cin >> a[i] >> b[i] >> c[i];
  if (check()) cout << "beep" << endl;
  else cout << "lie!" << endl;
  return 0;
}
