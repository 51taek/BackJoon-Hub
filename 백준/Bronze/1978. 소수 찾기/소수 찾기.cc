#include <bits/stdc++.h>
using namespace std;

int n;

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int ans = 0;

  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(a==1) continue;
    bool so = true;
    for(int j=2;j<a;j++){
      if (a % j == 0){
        so = false;
        break;
      }
    }
    if(so == true) ans++;
  }

  cout << ans;
  
}