#include <bits/stdc++.h>
using namespace std;

int n;
int a[505];
int dp[505];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    a[x] = y;
  }

  dp[0] = 0;
  
  int max_len = 1;

  for (int i = 0; i < 505; i++) {
      for (int j = 0; j < i; j++) {
          if (a[j] < a[i]) {
              dp[i] = max(dp[i], dp[j] + 1);
          }
      }
      max_len = max(max_len, dp[i]);
  }

  cout << n - max_len;

  
}