#include <bits/stdc++.h>
using namespace std;

char board[20][20];
bool vis[20][20];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define X first
#define Y second

void down() {
  for(int j=0;j<6;j++) {
    int idx = 11; 

    for(int i=11;i>=0;i--) {
      if(board[i][j] != '.') {
        board[idx][j] = board[i][j];
        if(idx != i) board[i][j] = '.';
        idx--;
      }
    }

    for(int i = idx; i >= 0; i--) {
      board[i][j] = '.';
    }
  }
}

void crash(vector<pair<int,int>> &v){
  for(int i=0;i<v.size();i++){
    board[v[i].X][v[i].Y] = '.';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ans = 0;

  for(int i=0;i<12;i++){
    string s;
    cin >> s;
    for(int j=0;j<6;j++){
      board[i][j] = s[j];
    }
  }

  while(1){
    bool is_crash = false;

    fill(&vis[0][0], &vis[0][0] + 400, 0);

    for(int i=0;i<12;i++){
      for(int j=0;j<6;j++){
        if(board[i][j] == '.' || vis[i][j]) continue;

        queue<pair<int,int>> q;
        vector<pair<int,int>> v;

        vis[i][j] = 1;
        q.push({i,j});

        int block = 0;

        while(!q.empty()){
          auto cur = q.front(); q.pop();
          block++;
          v.push_back({cur.X,cur.Y});

          for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if(vis[nx][ny]) continue;
            if(board[cur.X][cur.Y] != board[nx][ny]) continue;

            vis[nx][ny] = 1;
            q.push({nx,ny});
          }
        }

        if(block >= 4){
          crash(v);
          is_crash = true;
        }
      }
    }

    if(is_crash){
      ans++;
    }
    down();

    if(!is_crash) break;
  }

  cout << ans;
    
  
}