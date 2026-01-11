#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int en = 0;
  int odd = 0;
  int m = 0;

  for(int st=0;st<n;st++){

    while(en < n){
      if(a[en] % 2 == 1){
        if(odd == k) break;
        odd++;
      }
      en++;
    }

    m = max(m, en - st - odd);

    if(a[st] % 2 == 1) odd--;
  }

  cout << m;
  
}