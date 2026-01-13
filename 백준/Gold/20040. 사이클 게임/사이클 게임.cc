#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p(500005, -1);

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
  p[v] = u;
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=1;i<=m;i++){
    int a, b;
    cin >> a >> b;
    if(!uni(a,b)){
      cout << i;
      return 0;
    }
  }

  cout << 0;
}