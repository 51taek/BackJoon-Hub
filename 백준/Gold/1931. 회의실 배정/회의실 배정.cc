#include <bits/stdc++.h>
using namespace std;

int n;

#define X first
#define Y second

vector<pair<int,int>> v;

bool tmp(pair<int, int> a, pair<int, int> b){
  if(a.Y == b.Y) return a.X < b.X;  
  return a.Y < b.Y;  
}

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

  sort(v.begin(), v.end(), tmp);

  int ans = 0;
  int time = 0;

  for(int i=0;i<n;i++){
    if(v[i].X < time) continue;
    else {
      ans++;
      time = v[i].Y;
    }
  }

  cout << ans;

  
}