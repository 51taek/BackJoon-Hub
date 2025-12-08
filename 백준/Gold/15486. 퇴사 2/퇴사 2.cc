#include <bits/stdc++.h>
using namespace std;

int n;
int p[1500005];
long long dp[1500005];
int t[1500005];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> t[i] >> p[i];
  }

  for(int i=n;i>=0;i--){
    if(i + t[i] < n+1){
      dp[i] = max(dp[i + t[i]] + p[i], dp[i+1]);
    } else {
      dp[i] = dp[i+1];
    }
  }

  cout << *max_element(dp, dp+n+1);
}