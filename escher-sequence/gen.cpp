#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
int maxl = 1000;
string bits = "01";

string gen_random() {
  return rnd.next("[0-1]{1, 1000}");
}

string gen_pure(int len) {
  if ((len / 2) == 0) return "";
  string a = "";
  for (int i=0; i<len/2; i++) {
    int v = rnd.next(0, 1);
    a.push_back(bits[v]);
  }
  string res;
  res.resize(len);
  for (int i=0; i<len/2; i++) res[i] = a[i];
  for (int i=len/2; i<len; i++) res[i] = a[len-1-i] == '0'? '1': '0';
  return res;
}

string gen_hybrid(int tot) {
  int lena = rnd.next(1, tot);
  int lenb = rnd.next(1, tot - lena);
  string s = "";
  for (int i=0; i<lena; i++) {
    int b = rnd.next(0, 1);
    s.push_back(bits[b]);
  }
  s += gen_pure(lenb);
  return s;
}

string gen_hybrid2(int tot) {
  int lena = rnd.next(1, tot);
  int lenb = rnd.next(1, tot - lena);
  string s = gen_pure(lenb);
  for (int i=0; i<lena; i++) {
    int b = rnd.next(0, 1);
    s.push_back(bits[b]);
  }
  return s;
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  string t = string(argv[1]);
  string res;
  if (t == "random") {
    res = gen_random();
  }
  else if (t == "hybrid"){
    res = gen_hybrid(rnd.next(1, maxl));
  }
  else if (t == "hybrid-max") {
    res = gen_hybrid(maxl);
  }
  else if (t == "hybrid2") {
    res = gen_hybrid2(rnd.next(1, maxl));
  }
  else if (t == "hybrid2-max") {
    res = gen_hybrid2(maxl);
  }
  else if (t == "pure") {
    int len = rnd.next(1, maxl/2);
    res = gen_pure(len * 2);
  }
  else if (t == "pure-max") {
    res = gen_pure(maxl);
  }
  cout << res << endl;
  return 0;
}
