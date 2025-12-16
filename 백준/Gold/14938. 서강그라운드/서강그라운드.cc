#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int re[200];

#define X first
#define Y second

vector<pair<int,int>> g[200];
int d[200];

const int INF = 0x3f3f3f3f;

int func(int st){
  int ans = 0;
  fill(d, d+200, INF);

  priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>> > pq;

  d[st] = 0;
  pq.push({d[st],st});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(cur.X != d[cur.Y]) continue;
    ans += re[cur.Y];

    for(auto nxt: g[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      if(d[cur.Y] + nxt.X > m) continue;

      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
    }
  }

  return ans;
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> r;

  for(int i=1;i<=n;i++){
    cin >> re[i];
  }

  for(int i=0;i<r;i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({cost,y});
    g[y].push_back({cost,x});
  }

  int ans = 0;
  for(int i=1;i<=n;i++){
    ans = max(ans, func(i));
  }

  cout << ans;
  
}