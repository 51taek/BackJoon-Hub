#include <bits/stdc++.h>
using namespace std;

int h, w;

int a[505];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> h >> w;

  for(int i=0;i<w;i++){
    cin >> a[i];
  }

  int ans = 0;

  for(int i=1;i<w-1;i++){
    int lm = 0;
    int rm = 0;

    for(int j=0;j<i;j++){
      lm = max(lm, a[j]);
    }

    for(int j=i;j<w;j++){
      rm = max(rm, a[j]);
    }

    int m = min(lm, rm);

    if(m > a[i]){
      ans += m-a[i];
    }
  }


  cout << ans;

  

}