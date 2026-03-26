#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int a[105][105];
int d[105][105];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;

  cin >> m >> n;

  for(int i=1;i<=n;i++){
    string s;
    cin >> s;
    for(int j=1;j<=m;j++){
      a[i][j] = s[j-1] - '0';
    }
  }

  priority_queue<tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>> > pq;

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      d[i][j] = 1e9+10;

  d[1][1] = 0;
  pq.push({0, 1, 1});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    int cost, x, y;
    tie(cost, x, y) = cur;

    if(d[x][y] != cost) continue;
    for(int dir=0;dir<4;dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 1 || ny < 1 || nx > n || ny > m) continue;

      int nc = cost + a[nx][ny];
      
      if(nc < d[nx][ny]){
        d[nx][ny] = nc;
        pq.push({nc, nx, ny});
      }
    }
  }


  cout << d[n][m];

  
}