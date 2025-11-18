#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
vector<pair<int,int>> adj[1005];
int d[1005];

const int INF = 1e10+10;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({cost,b});
  }

  fill(d,d+n+1,INF);

  priority_queue < pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>> > pq;
  

  int st, en;
  cin >> st >> en;

  d[st] = 0;
  pq.push({d[st], st});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue;

    for(auto nxt: adj[cur.Y]){
      if(d[nxt.Y] <= nxt.X + d[cur.Y]) continue;
      d[nxt.Y] = nxt.X + d[cur.Y];
      pq.push({d[nxt.Y], nxt.Y});
    }
  }

  cout << d[en];

  

  
}