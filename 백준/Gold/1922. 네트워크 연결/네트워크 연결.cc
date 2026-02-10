#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> g[1005];
int chk[1005];
int cnt = 0;

#define X first
#define Y second


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int x, y, c;
    cin >> x >> y >> c;
    g[x].push_back({c,y});
    g[y].push_back({c,x});
  }

  priority_queue<tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>> > pq;

  chk[1] = 1;
  for(auto nxt: g[1]){
    pq.push({nxt.X, 1, nxt.Y});
  }
  int ans = 0;
  
  while(!pq.empty()){
    int cost, st, en;
    tie(cost, st, en) = pq.top(); pq.pop();

    if(chk[en]) continue;

    ans += cost;
    cnt++;
    chk[en] = 1;

    if(cnt == n-1){
      cout << ans;
      return 0;
    }

    for(auto nxt: g[en]){
      pq.push({nxt.X, en, nxt.Y});
    }
  }


  
}