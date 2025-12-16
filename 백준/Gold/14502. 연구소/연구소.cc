#include <bits/stdc++.h>
using namespace std;

int n ,m;
int a[10][10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define X first
#define Y second

int answer = 0;

int bfs(){

  bool vis[10][10];
  int tmp[10][10];
  
  memcpy(tmp, a, sizeof(a));
  memset(vis, 0, sizeof(vis));

  queue<pair<int,int>> q;
  
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(tmp[i][j] == 2){
              q.push({i,j});
              vis[i][j] = 1;
          }
      }
  }

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0;dir<4;dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(tmp[nx][ny] != 0 || vis[nx][ny] == 1) continue;

      tmp[nx][ny] = 2;
      vis[nx][ny] = 1;
      q.push({nx,ny});

    }
  }
  
  int cnt = 0;
  for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
          if(tmp[i][j] == 0) cnt++;
  
  return cnt;
}

void func(int idx, int wallCnt){
    if(wallCnt == 3){
        answer = max(answer, bfs());
        return;
    }
    if(idx == n*m) return;

    int x = idx / m;
    int y = idx % m;

    if(a[x][y] == 0){
        a[x][y] = 1;
        func(idx + 1, wallCnt + 1);
        a[x][y] = 0;
    }

    func(idx + 1, wallCnt);
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

  func(0,0);

  cout << answer;
  
  
}