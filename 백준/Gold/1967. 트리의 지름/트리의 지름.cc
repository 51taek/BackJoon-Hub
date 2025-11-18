#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> adj[10005];
bool vis[10005];

#define X first
#define Y second

int mxdist, mxnode;

void dfs(int cur, int dist){
  if(mxdist < dist){
    mxnode = cur;
    mxdist = dist;
  }
  for(auto nxt: adj[cur]){
    if(vis[nxt.X]) continue;
    vis[nxt.X] = 1;
    dfs(nxt.X, nxt.Y + dist);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0;i<n-1;i++){
    int a, b, cost;
    cin >> a >> b >> cost;
    adj[a].push_back({b,cost});
    adj[b].push_back({a,cost});
  }

  vis[1] = 1;
  dfs(1,0);
  fill(vis, vis+10005, 0);
  vis[mxnode] = 1;
  dfs(mxnode,0);

  cout << mxdist;
  
}