#include <bits/stdc++.h>
using namespace std;

int n, m;

int moveTo[105];

#define X first
#define Y second

int board[105];
int dist[105];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    moveTo[x] = y;
  }

  for(int i=0;i<m;i++){
    int x, y;
    cin >> x >> y;
    moveTo[x] = y;
  }

  queue<int> q;
  fill(dist, dist + 101, -1);

  q.push(1);
  dist[1] = 0;

  while(!q.empty()){
    int cur = q.front(); q.pop();

    for(int i=1;i<=6;i++){
      int nx = cur + i;
      if(nx < 0 || nx > 100) continue;

      if(moveTo[nx] != 0){
        nx = moveTo[nx];
      }
      if(dist[nx] != -1) continue;

      
      q.push(nx);
      dist[nx] = dist[cur] + 1;
    }
  }
  
  cout << dist[100];
  
}