#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> adj[1000];
long long d[1000];

#define X first
#define Y second

const int INF = 10e9+10;

long long func(int st, int en){
  
  priority_queue<pair<int,int>,
  vector<pair<int,int>>,
  greater<pair<int,int>> > pq;

  fill(d,d+1000,INF);

  d[st] = 0;
  pq.push({0,st});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();

    if(d[cur.Y] != cur.X) continue;
    for(auto nxt: adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }

  return d[en];
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int u, v, cost;
    cin >> u  >> v >> cost;
    adj[u].push_back({cost,v});
    adj[v].push_back({cost,u});
  }

  int p1, p2;
  cin >> p1 >> p2;

  long long ans1 = func(1,p1) + func(p1,p2) + func(p2,n);
  long long ans2 = func(1,p2) + func(p2,p1) + func(p1,n);

  
  long long ans = min(ans1,ans2);
  if(ans >= INF) cout << -1;
  else cout << ans;

  
  
}