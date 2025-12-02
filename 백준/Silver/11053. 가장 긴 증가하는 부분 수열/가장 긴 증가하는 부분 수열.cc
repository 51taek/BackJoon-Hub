#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int dp[1005];


int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
    dp[i] = 1;
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
    }
  }

  int m = 0;
  for(int i=0;i<n;i++){
    m = max(m, dp[i]);
  }

  cout << m;

}