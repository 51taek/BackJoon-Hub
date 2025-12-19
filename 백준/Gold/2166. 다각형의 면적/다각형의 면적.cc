#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<long,long>> v;

#define X first
#define Y second

long long area(pair<long,long> a, pair<long,long> b, pair<long,long> c){
  return a.X*b.Y + b.X*c.Y + c.X*a.Y - b.X*a.Y - c.X*b.Y - a.X*c.Y;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long ans = 0;
  
  cin >> n;

  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    v.push_back({x,y});
  }

  for(int i=2;i<n;i++){
    ans += area(v[0], v[i-1], v[i]);
  }

  ans = llabs(ans);

  if(ans % 2 == 0)
      cout << ans / 2 << ".0\n";
  else
      cout << ans / 2 << ".5\n";
  
}