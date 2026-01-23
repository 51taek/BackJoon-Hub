#include <bits/stdc++.h>
using namespace std;

int n;
int a[30][30];
int dist[30][30];

#define X first
#define Y second

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  int x, y;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
      if(a[i][j] == 9){
        x = i;
        y = j;
        a[i][j] = 0;
      }
    }
  }

  int size = 2;
  int ans = 0;
  int eatCnt = 0;

  while(true){
    priority_queue<tuple<int,int,int>,
      vector<tuple<int,int,int>>,
      greater<tuple<int,int,int>> > pq;

    for(int i=0; i<n; i++) fill(dist[i], dist[i]+n, -1);

    pq.push({0,x,y});
    dist[x][y] = 0;

    bool eat = false;

    while(!pq.empty()){
      int d,r,c;
      tie(d,r,c) = pq.top(); pq.pop();

      if(a[r][c] != 0 && a[r][c] < size){
        ans += d;
        eatCnt++;

        if(eatCnt == size){
          eatCnt = 0;
          size++;
        }

        a[r][c] = 0;
        x = r; y = c;
        eat = true;
        break;
        
      }

      for(int dir=0;dir<4;dir++){
        int nr = r + dx[dir];
        int nc = c + dy[dir];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (dist[nr][nc] != -1 || a[nr][nc] > size) continue;

        dist[nr][nc] = d + 1;
        pq.push({d + 1, nr, nc});
      }
    }

    if (!eat) break;
  }
  cout << ans;
  
}