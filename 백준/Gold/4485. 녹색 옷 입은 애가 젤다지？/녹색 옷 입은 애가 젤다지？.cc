#include <bits/stdc++.h>
using namespace std;

int t;

#define X first
#define Y second

int a[150][150];
int dist[150][150];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, tc = 1;

  while(cin >> n && n != 0){

    for(int i=0;i<150;i++)
      for(int j=0;j<150;j++){
        a[i][j] = 0;
        dist[i][j] = INT_MAX;
      }
    
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin >> a[i][j];
      }
    }

    priority_queue<tuple<int,int,int>,
      vector<tuple<int,int,int>>,
      greater<tuple<int,int,int>> > pq;
    
    dist[0][0] = a[0][0];
    pq.push({a[0][0], 0, 0});
    

    while(!pq.empty()){
      int cost, x, y;
      
      tie(cost, x, y) = pq.top(); pq.pop();

      if (dist[x][y] < cost) continue;

      for(int dir=0;dir<4;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if (dist[nx][ny] > cost + a[nx][ny]) {
            dist[nx][ny] = cost + a[nx][ny];
            pq.push({dist[nx][ny], nx, ny});
        }
      }
    }

    cout << "Problem " << tc++ << ": " << dist[n - 1][n - 1] << "\n";
  }
}