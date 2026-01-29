#include <bits/stdc++.h>
using namespace std;

int n;
int l, r;
int a[100][100];
bool vis[100][100];

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> l >> r;


  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }

  int answer = 0;

  while(true){

    for(int i=0; i<n; i++) fill(vis[i], vis[i]+n, false);

    bool is_moved = false;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(vis[i][j] == 1) continue;

        int sum = a[i][j];

        queue<pair<int,int>> q;
        vector<pair<int,int>> v;

        q.push({i,j});
        vis[i][j] = 1;
        v.push_back({i,j});

        while(!q.empty()){
          auto cur = q.front(); q.pop();

          for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny]) continue;

            int diff = abs(a[cur.X][cur.Y] - a[nx][ny]);
            if(diff >= l && diff <= r){
                vis[nx][ny] = 1;
                q.push({nx,ny});
                v.push_back({nx,ny}); 
                sum += a[nx][ny];
            }
          }
        }

        if(v.size() > 1){
            is_moved = true;
            int after = sum / v.size();
            for(auto cur : v){
                a[cur.X][cur.Y] = after;
            }
        }
      }

    }

    if(!is_moved) break;
    answer++;

  }

  cout << answer;
  return 0;

}