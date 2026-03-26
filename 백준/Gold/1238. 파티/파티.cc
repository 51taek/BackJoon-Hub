#include <bits/stdc++.h>
using namespace std;

int n, m, x;

vector<pair<int,int>> adj1[1005];
vector<pair<int,int>> adj2[1005];
int d1[1005];
int d2[1005];
const int INF = 1e9+10;

#define X first
#define Y second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> x;

  for(int i=0;i<m;i++){
    int u, v, cost;
    cin >> u >> v >> cost;
    adj1[u].push_back({cost,v});
    adj2[v].push_back({cost,u});
  }

  fill(d1,d1+1005,INF);

  priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>> > pq;

  d1[x] = 0;
  pq.push({0,x});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();

    if(d1[cur.Y] != cur.X) continue;

    for(auto nxt: adj1[cur.Y]){
      if(d1[nxt.Y] <= d1[cur.Y] + nxt.X) continue;
      d1[nxt.Y] = d1[cur.Y] + nxt.X;
      pq.push({d1[nxt.Y],nxt.Y});
    }
  }

  priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>> > pq2;

  fill(d2,d2+1005,INF);

  d2[x] = 0;
  pq2.push({0,x});

  while(!pq2.empty()){
    auto cur = pq2.top(); pq2.pop();
    if(d2[cur.Y] != cur.X) continue;

    for(auto nxt: adj2[cur.Y]){
      if(d2[nxt.Y] <= d2[cur.Y] + nxt.X) continue;
      d2[nxt.Y] = d2[cur.Y] + nxt.X;
      pq2.push({d2[nxt.Y], nxt.Y});
    }
    
  }

  int ans = 0;
  for(int i=1;i<=n;i++){
    ans = max(ans,d1[i] + d2[i]);
  }

  cout << ans;
  
}