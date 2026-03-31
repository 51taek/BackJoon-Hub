#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, x, y;
vector<pair<int, int>> v;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int ans = 0;

  cin >> n;
  
  for(int i=0;i<n;i++){
    cin >> x >> y;
    v.push_back({x,y});
  }

  sort(v.begin(), v.end());

  int st = v[0].X; int en = v[0].Y;

  for(int i=1;i<n;i++){
    if(en<v[i].X){
      ans += en - st;
      st = v[i].X;
      en = v[i].Y;
    } else {
      en = max(en, v[i].Y);
    }
  }
  ans += en - st;
  

  cout << ans;
}
