#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int apple[105][105];
int board[105][105];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

#define X first
#define Y second

map<int,char> m;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  cin >> n >> k;

  for(int i=0;i<k;i++){
    int a, b;
    cin >> a >> b;
    board[a][b] = 1;
  }

  cin >> l;

  for(int i=0;i<l;i++){
    int t;
    char dir;
    cin >> t >> dir;
    m.insert({t,dir});
  }

  deque<pair<int,int>> snake;

  int d = 0;
  int time = 0;
  int x = 1, y = 1;

  snake.push_back({1,1});
  board[1][1] = 2;

  while(true){
    time++;

    int nx = x + dx[d];
    int ny = y + dy[d];

    if(nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 2){
      cout << time;
      return 0;
    }

    if(board[nx][ny] == 1){
      snake.push_front({nx,ny});
      board[nx][ny] = 2;
    } else if(board[nx][ny] == 0){
      snake.push_front({nx,ny});
      board[nx][ny] = 2;
      auto p = snake.back();
      snake.pop_back();
      board[p.X][p.Y] = 0;
    }

    x = nx; y = ny;

    if(m.count(time)){
      if(m[time] == 'L') d = (d+3) %4;
      else d = (d+1) % 4;
    }
    
    
  }
  
}

