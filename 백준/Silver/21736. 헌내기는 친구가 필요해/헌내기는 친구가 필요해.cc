#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[800][800];
int vis[800][800];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define X first
#define Y second



int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  pair<int,int> st;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
      if(a[i][j] == 'I') st = {i,j};
    }
  }

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      vis[i][j] = -1;

  int ans = 0;
  queue<pair<int,int>> q;
  q.push(st);
  vis[st.X][st.Y] = 1;

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0;dir<4;dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(vis[nx][ny] != -1) continue;

      if(a[nx][ny] == 'X') continue;
      if(a[nx][ny] == 'P') ans++;

      q.push({nx,ny});
      vis[nx][ny] = 1;
     }
  }
  
  if(ans == 0) cout << "TT";
  else cout << ans;

  
}