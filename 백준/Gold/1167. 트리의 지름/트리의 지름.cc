#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100002];

#define X first
#define Y second

bool visited[100002];

int n;

int mCost;
int mNode;

void dfs(int n, int dist){
  if(mCost < dist){
    mCost = dist;
    mNode = n;
  }

  for(auto nxt: adj[n]){
    if(visited[nxt.Y]) continue;
    visited[nxt.Y] = 1;
    dfs(nxt.Y, dist+nxt.X);
  }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  while(n--){
    int a;
    cin >> a;
    while(1){
      int b, cost;
      cin >> b;
      if(b == -1) break;
      cin >> cost;
      adj[a].push_back({cost,b});
    }
  }

  visited[1] = 1;
  dfs(1,0);

  fill(visited, visited + 100002, false);

  visited[mNode] = 1;
  dfs(mNode,0);

  cout << mCost;
  
}