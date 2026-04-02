#include <bits/stdc++.h>
using namespace std;

bool vis[1000];
bool isTree;
vector<int> adj[1000];

void dfs(int cur, int prev){

  for(int nxt: adj[cur]){
    if(nxt == prev) continue;

    if(vis[nxt]){
      isTree = false;
      continue;
    }

    vis[nxt] = true;
    dfs(nxt, cur);
  }
  
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;

  while(1){
    int n, m;
    cin >> n >> m;
    if(n==0 && n==m) break;

    fill(vis, vis+n+1, 0);
    for (int i = 1; i <= n; i++)
      adj[i].clear();
    int ans = 0;

    for(int i=0;i<m;i++){
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    for (int i=1;i<=n;i++) {
      if (vis[i]) continue;
      vis[i] = true;
      isTree = true;
      dfs(i, -1);
      ans += isTree;
    }

    if(ans == 0) cout << "Case " << t << ": No trees.\n";
    else if(ans == 1) cout << "Case " << t << ": There is one tree.\n";
    else cout << "Case " << t << ": A forest of " << ans << " trees.\n";
    t++;

  }


  
}