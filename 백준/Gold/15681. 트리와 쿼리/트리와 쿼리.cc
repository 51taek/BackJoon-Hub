#include <bits/stdc++.h>
using namespace std;

int N, Q, R;
vector<int> g[100005];
int d[100005];

int dfs(int cur, int p){
  
  d[cur] = 1;
  for(int nxt: g[cur]){
    if (nxt == p) continue;  
    d[cur] += dfs(nxt, cur);
  }
  
  return d[cur];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> R >> Q;

  for(int i=0;i<N-1;i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(R,-1);

  for(int i=0;i<Q;i++){
    int q;
    cin >> q;
    cout << d[q] << "\n";
  }
  

  
}