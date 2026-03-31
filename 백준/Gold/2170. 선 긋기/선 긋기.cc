#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;

#define X first
#define Y second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    v.push_back({x,y});
  }

  sort(v.begin(), v.end());

  int st = v[0].X;
  int en = v[0].Y;
  long long ans = 0;
  for(int i=1;i<n;i++){
    if(en < v[i].X){
      ans += en - st;
      st = v[i].X;
      en = v[i].Y;
    } else{
      en = max(en, v[i].Y);
    }
  }

  ans += en-st;

  cout << ans;
  
}