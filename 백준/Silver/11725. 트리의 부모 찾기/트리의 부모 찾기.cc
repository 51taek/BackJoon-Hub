#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
int n;
int p[100002];

void dfs(int cur){
  for(int nxt: adj[cur]){
    if(p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
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

  dfs(1);
  
  for(int i=2;i<=n;i++){
    cout << p[i] << "\n";
  }
  
}