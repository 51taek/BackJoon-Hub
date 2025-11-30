#include <bits/stdc++.h>
using namespace std;

int k;

void func(int n, int a, int b){

  if(n==1){
    cout << a << " " << b << "\n";
    return ;
  }

  func(n-1, a, 6-a-b);
  cout << a << " " << b << "\n";
  func(n-1, 6-a-b, b);
  
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k;

  cout << (1<<k) -1 << "\n";
  func(k,1,3);
  
}