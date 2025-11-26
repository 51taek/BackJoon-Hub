#include <bits/stdc++.h>
using namespace std;

int n, m;
int t;
vector<int> adj[100];
vector<int> pt[100];

bool tp[100];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  cin >> t;
  for(int i=0;i<t;i++){
    int x;
    cin >> x;
    tp[x] = 1;
  }

  for(int i=0;i<m;i++){
    int no; cin >> no;

    int prv, nxt;
    cin >> prv;
    pt[i].push_back(prv);

    while(--no) {
      cin >> nxt;
      pt[i].push_back(nxt);
      adj[nxt].push_back(prv);
      adj[prv].push_back(nxt);
      swap(prv, nxt);
    }
  }

  bool visited[100];
  fill(visited, visited + 100, false);
  queue<int> q;

  for(int i = 1; i <= n; i++)
    if(tp[i]){
      q.push(i);
      visited[i] = 1;
    } 

    while(!q.empty()){
      int cur = q.front(); q.pop();
      for(int nxt: adj[cur]){
        if(visited[nxt]) continue;
        tp[nxt] = 1;
        q.push(nxt);
        visited[nxt] = 1;
      }
  
  }

  int ans = 0;
  for(int i=0;i<m;i++){
      bool b = false;
      for(int p: pt[i]) {
        if(visited[p]) b = true;
      }
      if(!b) ans++;
  }

  cout << ans;

}