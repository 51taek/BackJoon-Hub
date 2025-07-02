#include <bits/stdc++.h>
using namespace std;

int n, m;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

   cin >> n >> m;

  int sm = min(n,m);
  int mn = 0;
  // int mx = 10000;
  for(int i=1;i<=sm;i++){
    if(n % i == 0 && m % i == 0){
      mn = max(mn,i);
    }
  }
  cout << mn << "\n";

  int a = n;
  int b = m;

  while(1){
    if(a==b){
      cout << a;
      return 0;
    } else if(a > b){
      b += m;
    } else{
      a += n;
    }
  }

  
  return 0;
}