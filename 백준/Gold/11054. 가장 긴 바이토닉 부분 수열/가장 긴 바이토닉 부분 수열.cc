#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int up[1005];
int down[1005];
int dp[1005];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  fill(up, up + n + 1, 1);
  fill(down, down + n + 1, 1);

  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[j] < a[i]) up[i] = max(up[i], up[j] + 1);
    }
  }

  for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>i;j--){
      if(a[j] < a[i]) down[i] = max(down[i], down[j] + 1);
    }
  }

  int ans = 0;
  for(int i=0;i<n;i++){
    dp[i] = up[i] + down[i] - 1;
    ans = max(ans, dp[i]);
  }


  cout << ans;
  
}