#include <bits/stdc++.h>
using namespace std;

int a[100005];
int dp[100005][5][5];
vector<int> v;

const int INF = 1e9;

int cost(int now, int nxt){
  if(now == nxt) return 1;
  if(now == 0) return 2;
  if(abs(now - nxt) == 2) return 4;
  return 3;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int ans = INF;

  int x;
  while(cin >> x){
    if(x == 0) break;
    v.push_back(x);
  }

  for(int i=0;i<=v.size();i++)
    for(int j=0;j<5;j++)
      for(int t=0;t<5;t++)
        dp[i][j][t] = INF;

  dp[0][0][0] = 0;

  for(int i=0;i<v.size();i++){
    int x = v[i];
    for(int l=0;l<5;l++){
      for(int r=0;r<5;r++){
        if(dp[i][l][r] == INF) continue;
        dp[i+1][x][r] = min(dp[i+1][x][r], dp[i][l][r] + cost(l,x));
        dp[i+1][l][x] = min(dp[i+1][l][x], dp[i][l][r] + cost(r,x));
      }
    }
  }

  int n = v.size();
  for (int l = 0; l < 5; l++)
      for (int r = 0; r < 5; r++)
          ans = min(ans, dp[n][l][r]);
  
  cout << ans;
  
}