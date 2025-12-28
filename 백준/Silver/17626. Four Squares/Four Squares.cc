#include <bits/stdc++.h>
using namespace std;

int n;
int dp[50002];

const int INF = 0x7fffffff;

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  fill(dp, dp+50002, INF);
  dp[0] = 0;

  for(int i=1;i<=n;i++){
    for(int j=1;j*j<=i;j++){
      dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
  }

  cout << dp[n];
  
}