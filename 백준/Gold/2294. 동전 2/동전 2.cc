#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[105];
int dp[10200];

const int INF = 1e9;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  fill(dp, dp + k + 1, INF);
  dp[0] = 0;

  for(int i=1;i<=k;i++){
    for(int j=0;j<n;j++){
      if(i - a[j] >= 0){
        dp[i] = min(dp[i - a[j]] + 1, dp[i]);
      }
    }
  }

  if(dp[k] == INF) cout << -1;
  else cout << dp[k];

  
}