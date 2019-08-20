#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
const string s = "abcdefghijklmnopqrstuvwxyz";

string gen_worst() {
  string res = "";
  for (int i=0; i<49; i++) res.push_back('a');
  res.push_back('b');
  res = res + res;
  assert(res.size() == 100);
  return res;
}

string gen_pat() {
  string res = rnd.next("[a-f]{2, 10}");
  int len = rnd.next(20, 100);
  while ((int)res.size() < len) {
    int lp = rnd.next(0, (int)res.size() / 2);
    if (lp > 0) {
      string sub = res.substr(0, lp);
      res += sub;
    }
  }
  if ((int)res.size() > len) return res.substr(0, len);
  else return res;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    if (string(argv[1]) == "random")
      cout << rnd.next("[a-z]{1, 100}") << endl;
    else if (string(argv[1]) == "worst") 
      cout << gen_worst() << endl;
    else if (string(argv[1]) == "pat")
      cout << gen_pat() << endl;
    //cout << rnd.next(1, 10) << endl; /* Random number in the range [1,10]. */
    //cout << rnd.next("[a-zA-Z0-9]{1,1000}") << endl;  /* Random word of length [1,1000]. */
}
