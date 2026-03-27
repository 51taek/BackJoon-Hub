#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10][10];
int b[10][10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int,int>> camera;

#define X first
#define Y second

int mn = INT_MAX;

void upd(int x, int y, int dir){
  dir %= 4;
  while(1){
    x += dx[dir];
    y += dy[dir];

    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(b[x][y] == 6) return;
    if(b[x][y] != 0) continue;
    b[x][y] = 7;
  }
}

void dfs(int idx){
  if(idx == camera.size()){
    int val = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        val += (b[i][j] == 0);

    mn = min(mn, val);
    return;
  }

  int x = camera[idx].X;
  int y = camera[idx].Y;
  int type = a[x][y];

  int backup[10][10];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      backup[i][j] = b[i][j];

  for(int dir = 0; dir < 4; dir++){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        b[i][j] = backup[i][j];

    if(type == 1){
      upd(x, y, dir);
    }
    else if(type == 2){
      upd(x, y, dir);
      upd(x, y, dir + 2);
    }
    else if(type == 3){
      upd(x, y, dir);
      upd(x, y, dir + 1);
    }
    else if(type == 4){
      upd(x, y, dir);
      upd(x, y, dir + 1);
      upd(x, y, dir + 2);
    }
    else{ 
      upd(x, y, dir);
      upd(x, y, dir + 1);
      upd(x, y, dir + 2);
      upd(x, y, dir + 3);
    }

    dfs(idx + 1);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
      b[i][j] = a[i][j];
      if(a[i][j] >= 1 && a[i][j] <= 5){
        camera.push_back({i, j});
      }
    }
  }

  dfs(0);

  cout << mn;
}