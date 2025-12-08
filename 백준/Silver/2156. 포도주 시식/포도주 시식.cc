#include <bits/stdc++.h>
using namespace std;

int n;
int a[10005];
int dp[10005];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  dp[0] = a[0];

  for(int i=1;i<=n;i++){
    dp[i] = max({dp[i-1], dp[i-2]+a[i], dp[i-3] + a[i-1] + a[i]});
  }

  cout << *max_element(dp, dp + n);


  return 0;
}