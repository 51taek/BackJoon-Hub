#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p(202, -1);
int a[1005];

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

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> a[j];
      if(a[j] == 1){
        uni(i,j);
      }
    }
  }

  vector<int> plan(m);
  for(int i = 0; i < m; i++){
      cin >> plan[i];
  }

  for(int i=1;i<m;i++){
    if(find(plan[i]) != find(plan[i-1])){
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}