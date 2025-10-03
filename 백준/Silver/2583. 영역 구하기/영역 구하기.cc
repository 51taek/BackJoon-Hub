#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[105][105];
bool vis[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, k;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;

  for(int i=0;i<k;i++){
    int stx, sty, enx, eny;
    cin >> stx >> sty >> enx >> eny;
    for(int w=stx;w<enx;w++){
      for(int h=sty;h<eny;h++){
        board[h][w] = 1;
      }
    }
  }

  queue<pair<int,int>> q;
  vector<int> v;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(board[i][j] == 1 || vis[i][j]) continue;
      q.push({i,j});
      vis[i][j] = 1;
      int size = 1;
      while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir=0;dir<4;dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if(board[nx][ny] == 1 || vis[nx][ny] == 1) continue;

          q.push({nx,ny});
          vis[nx][ny] = 1;
          size++;
        }
      }
      v.push_back(size);
    }
    
  }

  sort(v.begin(),v.end());
  cout << v.size() << "\n";
  for(int i=0;i<v.size();i++){
    cout << v[i] << " ";
  }

  return 0;
}