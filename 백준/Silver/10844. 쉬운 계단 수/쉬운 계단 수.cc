#include <bits/stdc++.h>
using namespace std;

int n;
int dp[105][10];

int mod = 1000000000;

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i = 1; i <= 9; i++) {
      dp[1][i] = 1;
  }

  for(int i=2;i<=n;i++){
    dp[i][0] = dp[i-1][1] % mod;
    dp[i][9] = dp[i-1][8] % mod;
    for(int j=1;j<=8;j++){
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod ;
    }
  }

  long long ans = 0;
  for(int i=0;i<=9;i++){
    ans += dp[n][i];
  }

  cout << ans % mod;
  
}