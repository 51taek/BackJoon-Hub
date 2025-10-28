#include <bits/stdc++.h>
using namespace std;

int dist[20002];

void bfs(int st, vector<vector<int>> &g, int n){

  queue<int> q;
  fill(dist, dist+n+1, -1);
  
  q.push(st);
  dist[st] = 0;

  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int nxt: g[cur]){
      if(dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;

  cin >> n >> m;

  vector<vector<int>> g(n+1);

  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bfs(1,g,n);

  int ans = 0;
  vector<int> v;

  for(int i=1;i<=n;i++){
    ans = max(ans, dist[i]);
  }

  for(int i=1;i<=n;i++){
    if(ans == dist[i]){
      v.push_back(i);
    }
  }

  sort(v.begin(),v.end());

  cout << v[0] << " " << ans << " " << v.size();
  
  
}