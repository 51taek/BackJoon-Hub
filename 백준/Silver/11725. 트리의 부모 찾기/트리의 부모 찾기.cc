#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
int n;
int p[100002];

void bfs(int cur){
  queue<int> q;
  q.push(cur);
  while(!q.empty()){
    int c = q.front(); q.pop();
    for(int nxt: adj[c]){
      if(p[nxt]) continue;
      q.push(nxt);
      p[nxt] = c;
    }
  }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0;i<n-1;i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  bfs(1);
  
  for(int i=2;i<=n;i++){
    cout << p[i] << "\n";
  }
  
}