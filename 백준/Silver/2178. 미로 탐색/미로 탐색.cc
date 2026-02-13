#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105][105];
int dist[105][105];

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<s.size();j++){
      a[i][j] = s[j] - '0';
    }
  }

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      dist[i][j] = -1;

  queue<pair<int,int>> q;
  q.push({0,0});
  dist[0][0] = 1;

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir=0;dir<4;dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(dist[nx][ny] != -1 || a[nx][ny] == 0) continue;

      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      q.push({nx,ny});
    }
  }

  cout << dist[n-1][m-1];
  
  
}