#include <bits/stdc++.h>
using namespace std;

int bfs(int st, vector<vector<int>> &weight, int n){

  vector<int> visited(n + 1, 0);
  int ans = 0;

  queue<int> q;
  q.push(st);
  visited[st] = 1;

  while(!q.empty()){
    int cur = q.front(); q.pop();

    for(int nxt: weight[cur]){
      if(visited[nxt] != 0) continue;
      ans++;
      visited[nxt] = 1;
      q.push(nxt);
    }
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> light(n+1);
  vector<vector<int>> heavy(n+1);

  for(int i=1;i<=m;i++){
    int a, b;
    cin >> a >> b;
    heavy[a].push_back(b);
    light[b].push_back(a);
  }

  

  int ans = 0;
  int mid = (n+1)/2;

  for(int i=1;i<=n;i++){
    int h = bfs(i, heavy,n);
    int l = bfs(i,light,n);
    if(h >= mid || l >= mid) ans++;
  }

  cout << ans;
  
}