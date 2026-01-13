#include <bits/stdc++.h>
using namespace std;

int test;

vector<int> p(1000005, -1);

int find(int x){
  if(p[x] < 0){
    return x;
  }
  return p[x] = find(p[x]);
}

bool uni(int x, int y){
  int u = find(x);
  int v = find(y);

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

  cin >> test;

  for(int t=1;t<=test;t++){
    fill(p.begin(), p.end(), -1);
    int n, k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
      int a, b;
      cin >> a >> b;
      uni(a,b);
    }
    int m;
    cin >> m;
    cout << "Scenario " << t << ":" << "\n";
    for(int i=0;i<m;i++){
      int x, y;
      cin >> x >> y;
      cout << (find(x) == find(y)) << "\n";
    }
    cout << "\n";
  }

  
}