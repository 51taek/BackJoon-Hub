#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e, st;
vector<pair<int,int>> adj[20005];
int d[20005];
const int INF = 1e9+10;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  cin >> v >> e;
  cin >> st;

  for(int i=0;i<e;i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({cost,b});
  }

  fill(d,d+v+1,INF);

  priority_queue< pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

  d[st] = 0;
  pq.push({0,st});
  
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt: adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
    }
  }

  for(int i=1;i<=v;i++){
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << "\n";
  }
  
}