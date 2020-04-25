#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 201 , mod = 1e9+7 , F = 100;

int dp[N][N][N][5];

inline pii nxt(int x , int y , int dir){
   pii pp = {-1 , -1};
   if(dir == 0)
      pp = {x + 1 , y};
   else if(dir == 1)
      pp = {x , y + 1};
   else if(dir == 2)
      pp = {x - 1 , y};
   else
      pp = {x , y - 1};
   if(pp.first < 0 || pp.first >= N || pp.second < 0 || pp.second >= N)
      pp = {-1 , -1};
   return pp;
}

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int m;
   cin >> m;
   int x , y;
   cin >> x >> y;
   x += F;
   y += F;
   int z , w;
   cin >> z >> w;
   z += F;
   w += F;
   dp[x][y][0][4] = 1;
   set < pair <pii , pii> > q;
   q.insert({{0 , 4} , {x , y}});
   int D = -1;
   while(q.size()){
      auto qq = *q.begin();
      q.erase(q.begin());
      pii xx = qq.second;
      int dir = qq.first.second;
      int dis = qq.first.first;
      int x = xx.first , y = xx.second;
      //cout << x << " " << y << " " << dir << " " << dp[x][y][dis][dir] << endl;
      if(x == z && y == w){
         D = dis;
         break;
      }
      for(int i = 0 ; i < 4 ; i++){
         pii g = nxt(x , y , i);
         if(g == make_pair(-1 , -1))
            continue;
         if(i == dir && dis && dis % m == 0)
            continue;
         dp[g.first][g.second][dis + 1][i] += dp[x][y][dis][dir];
         dp[g.first][g.second][dis + 1][i] %= mod;
         q.insert({{dis + 1 , i} , {g.first , g.second}});
      }
   }
   int ans2 = 0;
   for(int i = 0 ; i < 4 ; i++){
      ans2 += dp[z][w][D][i];
      ans2 %= mod;
   }
   cout << D << " " << ans2 << endl;
   return 0;
}
