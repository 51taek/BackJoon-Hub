#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=1;i<=n;i++){
    cin >> a[i];
  }

  sort(a, a+n+1);
  int ans = 0;

  for(int i=1;i<=n;i++){
    ans = max(ans, a[i] * (n-i+1));
  }

  cout << ans;

  

  
}