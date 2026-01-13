#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p(1000001, -1);

int find(int x){
  if(p[x] < 0){
    return x;
  }
  return p[x] = find(p[x]);
}

bool uni(int a, int b){
  int u = find(a);
  int v = find(b);

  if(u == v) return false;

  if(p[v] < p[u]) swap(u,v);

  if(p[v] == p[u]) p[u]--;

  p[v] = u;
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int z, a, b;
    cin >> z >> a >> b;
    if(z == 0) uni(a,b);
    if(z == 1){
      int x = find(a);
      int y = find(b);
      if(x == y) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  
}