#include <bits/stdc++.h>
using namespace std;

int n, m, h;

int side[35][15];

int t;

bool check(){
  for(int j=1;j<=n;j++){
    int current = j;
    for(int i=1;i<=h;i++){
      if(side[i][current] == 1) current++;
      else if(current > 1 && side[i][current-1] ==1) current--;
    }
    if(current != j) return false;
  }

  return true;
}

void dfs(int cnt, int r){
  if(cnt == t){
    if(check()){
      cout << t;
      exit(0);
    }
    return ;
  }

  for(int i=r;i<=h;i++){
    for(int j=1;j<n;j++){
      if(side[i][j] == 1 || side[i][j-1] || side[i][j+1]) continue;

      side[i][j] = 1;
      dfs(cnt+1, i);
      side[i][j] = 0;
    }
    
  }
  
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> h;

  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    side[a][b] = 1;
  }

  for(int i=0;i<=3;i++){
    t = i;
    dfs(0, 1);
  }

  cout << -1 << "\n";
  
}