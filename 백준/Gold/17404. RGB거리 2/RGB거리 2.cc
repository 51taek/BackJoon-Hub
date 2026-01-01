#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005][5];
int dp[1005][5];

const int INF = 1e9;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=3;j++){
      cin >> a[i][j];
    }
  }

  int ans = INF;

  dp[1][1] = a[1][1];
  dp[1][2] = INF;
  dp[1][3] = INF;

  for(int i=2;i<=n;i++){
    dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + a[i][1];
    dp[i][2] = min(dp[i-1][3], dp[i-1][1]) + a[i][2];
    dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + a[i][3];
  }

  int minN = min({dp[n][2], dp[n][3]});
  ans = min(ans,minN);

  dp[1][1] = INF;
  dp[1][2] = a[1][2];
  dp[1][3] = INF;

  for(int i=2;i<=n;i++){
    dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + a[i][1];
    dp[i][2] = min(dp[i-1][3], dp[i-1][1]) + a[i][2];
    dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + a[i][3];
  }

  minN = min({dp[n][1], dp[n][3]});
  ans = min(ans,minN);

  dp[1][1] = INF;
  dp[1][2] = INF;
  dp[1][3] = a[1][3];

  for(int i=2;i<=n;i++){
    dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + a[i][1];
    dp[i][2] = min(dp[i-1][3], dp[i-1][1]) + a[i][2];
    dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + a[i][3];
  }

  minN = min({dp[n][1], dp[n][2]});

  
  ans = min(ans,minN);

  cout << ans;
  
}