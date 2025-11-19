#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, x;
vector<pair<int,int>> adj[1005];
int d[1005];
int dx[1005];

const int INF = 10e9+10;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> x;

  for(int i=0;i<m;i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({cost,b});
  }

  int ans = 0;

  priority_queue< pair<int,int>,
      vector<pair<int,int>>,
      greater<pair<int,int>> > pq;
  
  fill(dx,dx+1005,INF);

  dx[x] = 0;
  pq.push({0,x});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(dx[cur.Y] != cur.X) continue;
    for(auto nxt: adj[cur.Y]){
      if(dx[nxt.Y] <= dx[cur.Y] + nxt.X) continue;
      dx[nxt.Y] = dx[cur.Y] + nxt.X;
      pq.push({dx[nxt.Y], nxt.Y});
    }
  }

  for(int i=1;i<=n;i++){

    priority_queue< pair<int,int>,
      vector<pair<int,int>>,
      greater<pair<int,int>> > pq;

    fill(d,d+1005,INF);

    d[i] = 0;
    pq.push({0,i});
    while(!pq.empty()){
      auto cur = pq.top(); pq.pop();
      if(d[cur.Y] != cur.X) continue;
      for(auto nxt: adj[cur.Y]){
        if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
        d[nxt.Y] = d[cur.Y] + nxt.X;
        pq.push({d[nxt.Y],nxt.Y});
      }
    }

    ans = max(ans,d[x]+dx[i]);
    
  }

  cout << ans;
  
}