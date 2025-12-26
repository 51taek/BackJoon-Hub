#include <bits/stdc++.h>
using namespace std;

int r, c, t;

int a[55][55];
int tmp[55][55];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};

void windUp(int air){
  for (int i = air - 1; i > 0; i--) {
    a[i][0] = a[i - 1][0];
  }

  for (int j = 0; j < c - 1; j++){
    a[0][j] = a[0][j + 1];
  } 

  for (int i = 0; i < air; i++){
    a[i][c - 1] = a[i + 1][c - 1];
  } 

  for (int j = c - 1; j > 1; j--){
    a[air][j] = a[air][j - 1];
  } 

  a[air][1] = 0;
  a[air][0] = -1;
}

void windDown(int air){
  for(int i=air+1;i<r-1;i++){
    a[i][0] = a[i+1][0];
  }  
  for(int j=0;j<c-1;j++){
    a[r-1][j] = a[r-1][j+1];
  }
  for(int i=r-1;i>air;i--){
    a[i][c-1] = a[i-1][c-1];
  }
  for(int j=c-1;j>1;j--){
    a[air][j] = a[air][j-1];
  }
  
  a[air][1] = 0;
  a[air][0] = -1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c >> t;

  int up = -1;
  int down = -1;

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin >> a[i][j];
      if(a[i][j] == -1){
        if(up == -1) up = i;
        else down = i;
      }
    }
  }


  while(t--){
    memset(tmp, 0, sizeof(tmp));
    
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){

        if(a[i][j] == -1){
          tmp[i][j] = -1;
          continue;
        }

        if(a[i][j] >= 5){
          int cnt = 0;
          int sp = a[i][j] / 5;

          for(int dir=0;dir<4;dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(a[nx][ny] == -1) continue;

            tmp[nx][ny] += sp;
            cnt++;
          }
          tmp[i][j] += a[i][j] - sp*cnt;
        } else {
          tmp[i][j] += a[i][j];
        }
      }
    }  
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = tmp[i][j];
        }
    }

    windUp(up);
    windDown(down);
  }

  int ans = 0;

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(a[i][j] <= 0) continue;
      ans += a[i][j];
    }
  }

  cout << ans;
  
}