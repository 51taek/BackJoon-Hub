#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
int vis[1005][1005];

#define X first
#define Y second

int n, m;
int ans;

pair<int,int> move(int x, int y){
  if(a[x][y] == 'D') return {x+1,y};
  if(a[x][y] == 'U') return {x-1,y};
  if(a[x][y] == 'R') return {x,y+1};
  return {x,y-1};
}

void dfs(int x, int y){

  int nx, ny;
  vis[x][y] = 1;

  tie(nx,ny) = move(x, y);

  if(nx < 0 || ny < 0 || nx >=n || ny >= m) return;
  
  if(vis[nx][ny] == 0) dfs(nx,ny);
  else if(vis[nx][ny] == 1) ans++;

  vis[x][y] = 2;
  
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }

  ans = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(vis[i][j] == 0) dfs(i,j);
    }
  }

  cout << ans;
  
  
}