#include <bits/stdc++.h>
using namespace std;

vector<string> exist, need;
int n, m;

struct node {
  string name;
  vector<int> next;
};

vector<node> nodes;

vector<string> get_dirs(const string& path) {
  vector<string> res;
  for (int i=0; i<(int)path.size(); i++) {
    if (path[i] == '/') continue;
    int j = i;
    while (j+1 < (int)path.size() && path[j+1] != '/') j++;
    res.push_back(path.substr(i, j-i+1));
    i = j;
  }
  return res;
}

int insert(const vector<string>& dirs) {
  int id = 0;
  int cnt = 0;
  for (const string& dir: dirs) {
    bool flag = false;
    for (int i: nodes[id].next) if (nodes[i].name == dir) {
      flag = true;
      id = i;
      break;
    }
    if (!flag) {
      cnt++;
      nodes.push_back({dir, vector<int>()});
      nodes[id].next.push_back((int)nodes.size()-1);
      id = (int)nodes.size()-1;
    }
  }
  return cnt;
}

int do_case() {
  cin >> n >> m;
  nodes.clear();
  nodes.push_back({"/", vector<int>()});
  exist.resize(n);
  need.resize(m);
  for (int i=0; i<n; i++) {
    cin >> exist[i];
    vector<string> dirs = get_dirs(exist[i]);
    insert(dirs);
  }
  int res = 0;
  for (int i=0; i<m; i++) {
    cin >> need[i];
    vector<string> dirs = get_dirs(need[i]);
    res += insert(dirs);
  }
  return res;
}

int main() {
  cout << do_case() << endl;
  return 0;
}
