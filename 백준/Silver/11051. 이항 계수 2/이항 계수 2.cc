#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[1002][1002];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  cin >> n >> k;

  dp[1][1] = 1;
  dp[1][0] = 1;

  for(int i=2;i<=n;i++){
    dp[i][0] = 1;
    for(int j=1;j<=k;j++){
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
    }
  }

  cout << dp[n][k];

  

  
}