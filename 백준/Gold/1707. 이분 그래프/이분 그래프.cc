#include <bits/stdc++.h>
using namespace std;

int k;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k;

  while(k--){

    int v, e;
    cin >> v >> e;
    vector<int> g[20005];
    int vis[20005];
    fill(vis, vis + v + 1, 0);
    bool isPossible = true;

    for(int i=0;i<e;i++){
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    for(int i=1;i<=v;i++){
      if(vis[i] != 0) continue;

      queue<int> q;
      q.push(i);
      vis[i] = 1;

      while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt: g[cur]){
          if(vis[nxt] == 0){
            if(vis[nxt]) continue;
            vis[nxt] = 3 - vis[cur];
            q.push({nxt});
          } else if(vis[cur] == vis[nxt]){
            isPossible = false;
          }
        }
      }
    }

    if(isPossible) cout << "YES\n";
    else cout << "NO\n";
  }



}