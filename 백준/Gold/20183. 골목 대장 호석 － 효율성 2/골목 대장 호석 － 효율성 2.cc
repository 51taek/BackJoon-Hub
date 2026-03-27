#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
vector<pair<long long,int>> adj[100005];
long long d[100005];
const long long INF = 1e14;

#define X first
#define Y second

bool check(long long limit){
  priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>> > pq;

  fill(d, d+100005, INF);


  d[a] = 0;
  pq.push({0, a});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();

    if(d[cur.Y] != cur.X) continue;

    for(auto nxt: adj[cur.Y]){
      if(nxt.X > limit) continue;
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }

  return d[b] <= c;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> a >> b >> c;

  for(int i=0;i<m;i++){
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost,v});
    adj[v].push_back({cost,u});
  }

  long long l = 0;
  long long r = 0;

  for(int i=1;i<=n;i++){
    for(auto nxt: adj[i]){
      r = max(r, nxt.X);
    }
  }

  int ans = -1;
  
  while(l <= r){

    long long mid = (l + r) / 2;

    if(check(mid)){
      ans = mid;
      r = mid-1;
    } else{
      l = mid+1;
    }
  }


  cout << ans;
  

  
  
}