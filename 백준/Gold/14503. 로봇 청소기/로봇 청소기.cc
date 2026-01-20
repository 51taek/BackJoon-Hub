#include <bits/stdc++.h>
using namespace std;

int n, m;
int r, c, d;
int a[100][100];
int vis[100][100];

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool around(int x, int y){
  for(int dir=0;dir<4;dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if(a[nx][ny] == 0) return true;
  }

  return false;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  cin >> r >> c >> d;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }

  int ans = 0;
  

  while(true){
    if(a[r][c] == 0){
      a[r][c] = 2;
      ans++;
    }

    if(around(r,c)){
      d = (d + 3) % 4;
      int nr = r + dx[d];
      int nc = c + dy[d];

      if(a[nr][nc] == 0){
        r = nr;
        c = nc;
      }
    } else {
      int back = (d + 2) % 4;
      int br = r + dx[back];
      int bc = c + dy[back];

      if(br < 0 || bc < 0 || br >= n || bc >= m || a[br][bc] == 1) {
          break; 
      }
      r = br;
      c = bc;
    }
    
  }

  cout << ans;
  
}