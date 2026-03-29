#include <bits/stdc++.h>
using namespace std;

int n, m;

int a[20];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a, a+n);

  int ans = 0;

  for(int i=n-1;i>=0;i--){
    if(a[i] <= m){
      int cnt = m / a[i];
      ans += cnt;
      m -= cnt * a[i];
    }
  }

  cout << ans;

  
}