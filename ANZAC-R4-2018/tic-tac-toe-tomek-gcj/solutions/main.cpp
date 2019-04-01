#include <bits/stdc++.h>
using namespace std;
vector<string> g;

char check_winner(const string& s) {
  int cntx=0, cntt=0, cnto=0;
  for (char i: s) {
    if (i == '.') return '0';
    if (i == 'X') cntx++;
    if (i == 'O') cnto++;
    if (i == 'T') cntt++;
  }
  if (cntx + cntt == 4) return 'X';
  if (cnto + cntt == 4) return 'O';
  return '0';
}

string do_case() {
  g.resize(4);
  for (int i=0; i<4; i++) {
    cin >> g[i];
  }
  char f;
  for (int i=0; i<4; i++) {
    f = check_winner(g[i]);
    if (f == 'X') return "X won";
    if (f == 'O') return "O won";
  }
  string s;
  for (int i=0; i<4; i++) {
    s = "";
    for (int j=0; j<4; j++) s.push_back(g[j][i]);
    char f = check_winner(s);
    if (f == 'X') return "X won";
    if (f == 'O') return "O won";
  }

  s = "";
  for (int i=0; i<4; i++) {
    s.push_back(g[i][i]);
  }
  f = check_winner(s);
  if (f == 'X') return "X won";
  if (f == 'O') return "O won";
  
  s = "";
  for (int i=0; i<4; i++) {
    s.push_back(g[i][3-i]);
  }
  f = check_winner(s);
  if (f == 'X') return "X won";
  if (f == 'O') return "O won";

  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++) if (g[i][j] == '.') return "Game has not completed";
  return "Draw";
}

int main() {
  cout << do_case() << endl;
  return 0;
}
