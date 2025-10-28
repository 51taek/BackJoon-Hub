#include <bits/stdc++.h>
using namespace std;

int n, m;

int bfs(int st, vector<vector<int>> &g){
  int ans = 0;
  queue<int> q;
  vector<int> visited(n + 1, 0);

  q.push(st);
  visited[st] = 1;

  while(!q.empty()){
    int cur = q.front(); q.pop();
    
    for(int nxt: g[cur]){
      if(visited[nxt] == 0){
        q.push(nxt);
        visited[nxt] = 1;
        ans++;
      }
    }
  }

  return ans;
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m;

  vector<vector<int>> g(n + 1);

  for(int i=1;i<=m;i++){
    int a, b;
    cin >> a >> b;
    g[b].push_back(a);
  }
  
  int answer = 0;
  int result[n];

  for(int i=1;i<=n;i++){
    result[i] = bfs(i,g);
    answer = max(answer, result[i]);
  }

  for(int i=1;i<=n;i++){
    if(result[i] == answer){
      cout << i << " ";
    }
  }
  
}