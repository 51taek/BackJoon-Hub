#include <bits/stdc++.h>
using namespace std;

int n, m;

int indeg[32005];
vector<int> adj[32005];
vector<int> ans;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=1;i<=m;i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    indeg[b]++;
  }

  queue<int> q;

  for(int i=1;i<=n;i++){
    if(indeg[i] == 0) q.push(i);
  }

  while(!q.empty()){
    int cur = q.front(); q.pop();
    ans.push_back(cur);
    for(int nxt: adj[cur]){
      indeg[nxt]--;
      if(indeg[nxt] == 0) q.push(nxt);
    }
  }
  

  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }

  
}