#include <bits/stdc++.h>
using namespace std;

int c, n;
int cost[30];
int people[30];
int dp[1105];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> c >> n;

  for(int i=0;i<n;i++){
    cin >> cost[i] >> people[i];
  }

  fill(dp, dp+1105, 1e9);
  dp[0] = 0;

  for(int i=0;i<n;i++){
    for(int j=people[i];j <= c+100; j++){
      dp[j] = min(dp[j], dp[j - people[i]] + cost[i]);
    }
  }

  int ans = 1e9;
  for (int i = c; i <= c + 100; i++) {
      ans = min(ans, dp[i]);
  }

  cout << ans;
}