#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[1002][1002];
int vis[1002][1002];
queue<pair<int,int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> m >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
      if(board[i][j] == 1){
        q.push({i,j});
        vis[i][j] = 0;
      }
      if(board[i][j] == 0)
        vis[i][j] = -1;
    }
  }

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir = 0; dir<4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(vis[nx][ny] != -1) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      q.push({nx,ny});
    }
  }

  int ans = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(vis[i][j] == -1){
        cout << -1;
        return 0;
      }
      ans = max(ans,vis[i][j]);
    }
  }

  cout << ans;
  return 0;
  
}