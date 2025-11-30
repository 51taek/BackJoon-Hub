#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int func(int k, int a, int b){

  if(k==0){
    return 0;
  }
  int half =  1<<(k-1);

  if(a < half && b < half) return func(k-1, a, b);
  if(a < half && b >= half) return half*half + func(k-1, a, b - half);
  if(a >= half && b < half) return 2*half*half + func(k-1, a - half, b);
  return 3*half*half + func(k-1, a - half, b - half);
  
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> r >> c;

  cout << func(n,r,c);

  
}