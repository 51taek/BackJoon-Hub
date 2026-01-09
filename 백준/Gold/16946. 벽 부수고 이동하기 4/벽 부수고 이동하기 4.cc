#include <bits/stdc++.h> 
using namespace std;

int n, m;
int a[1005][1005];
int vis[1005][1005];
vector<int> v;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y, int id){
  
  queue<pair<int,int>> q;
  q.push({x,y});
  vis[x][y] = id;
  int cnt = 0;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    cnt++;
    for(int dir=0;dir<4;dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(vis[nx][ny] != -1 || a[nx][ny] == 1) continue;

      vis[nx][ny] = id;
      q.push({nx,ny});
    }
  }
  v[id] = cnt;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      vis[i][j] = -1;

  for(int i=0; i<n; i++){
    string row;
    cin >> row; 
    for(int j=0; j<m; j++){
      a[i][j] = row[j] - '0'; 
      vis[i][j] = -1;
    }
  }
  
  v.resize(n * m);


  int id = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j] == 0 && vis[i][j] == -1){
        bfs(i, j, id);
        id++;
      }
    }
  }


  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j] != 0){
        int size = 1;
        set<int> s;
        for(int dir=0;dir<4;dir++){
          int nx = i + dx[dir];
          int ny = j + dy[dir];

          if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          int id = vis[nx][ny];
          if(vis[nx][ny] != -1)
            s.insert(id);
        }
        for(int i: s){
          size += v[i];
        }

        cout << size % 10;
      } else {
        cout << 0;
      }
    }
    cout << "\n";
  }

  
}