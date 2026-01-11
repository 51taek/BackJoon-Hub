#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[2000005];
int chk[2000005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int en = 0;
  int m = 0;

  for(int st=0;st<n;st++){

    while(en < n && chk[a[en]] < k){
      chk[a[en]]++;
      en++;
    }

    m = max(m, en - st);
    

    chk[a[st]]--;
    
  }

  cout << m;

  
}