#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll x,y,c;

ll mod(ll a, ll b){
  if(b==1) return a % c;
  ll result = 0;

  ll half = mod(a,b/2);
  result = (half * half) % c;
  
  if(b % 2) result = (result * a) % c;
  return result;
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> x >> y >> c;

  cout << mod(x,y);
  
}