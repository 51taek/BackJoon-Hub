#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[1002][1002];
int dist[1002][1002][2];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(){
  queue<tuple<int,int,int>> q;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      dist[i][j][0] = dist[i][j][1] = -1;

  q.push({0,0,0});
  dist[0][0][0] = dist[0][0][1] = 1;

  while(!q.empty()){
    int x, y, punch;
    tie(x, y, punch) = q.front(); q.pop();
    if(x == n-1 && y == m-1) return dist[x][y][punch];

    for(int dir=0;dir<4;dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;

      if(board[nx][ny] == '0' && dist[nx][ny][punch] == -1){
        q.push({nx,ny,punch});
        dist[nx][ny][punch] = dist[x][y][punch] + 1;
      }

      if(!punch && board[nx][ny] == '1' && dist[nx][ny][1] == -1){
        q.push({nx,ny,1});
        dist[nx][ny][1] = dist[x][y][punch] + 1;
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
    }
  }

  cout << bfs();
  
  
}