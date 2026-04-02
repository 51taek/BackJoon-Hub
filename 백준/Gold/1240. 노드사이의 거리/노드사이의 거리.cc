#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> adj[1005];
bool vis[1005];


#define X first
#define Y second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n-1;i++){
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({c,v});
    adj[v].push_back({c,u});
  }

  for(int i=0;i<m;i++){
    int x, y;
    cin >> x >> y;
    queue<pair<int,int>> q;
    fill(vis, vis+n+1, 0);
    q.push({0,x});
    vis[x] = 1;
    while(!q.empty()){
      auto cur = q.front(); q.pop();

      if(cur.Y == y){
        cout << cur.X << "\n";
        break;
      }

      for(auto nxt: adj[cur.Y]){
        if(vis[nxt.Y]) continue;
        vis[nxt.Y] = 1;
        q.push({nxt.X + cur.X, nxt.Y});
      }
    }
  }

  

  
}