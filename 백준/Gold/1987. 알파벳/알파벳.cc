#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[25][25];
int maxN = 0;
bool used[26];


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void func(int x, int y, int cnt){
  
  maxN = max(maxN, cnt);
  
  for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

      int idx = a[nx][ny] - 'A';

      if(!used[idx]){
          used[idx] = true;
          func(nx, ny, cnt + 1);
          used[idx] = false; 
      }
  }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }

  used[a[0][0] - 'A'] = true;
  func(0,0,1);

  cout << maxN;
}
