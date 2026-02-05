#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y, k;

int a[30][30];
int mv[1005];
int dice[6];

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void roll(int dir){
  
  if(dir == 1){
    int t = dice[3];   
    dice[3] = dice[2]; 
    dice[2] = dice[5]; 
    dice[5] = dice[4]; 
    dice[4] = t;
  } else if(dir == 2){
    int t = dice[3];   
    dice[3] = dice[4]; 
    dice[4] = dice[5]; 
    dice[5] = dice[2]; 
    dice[2] = t;
  } else if(dir == 3){
    int t = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[0];
    dice[0] = t;
  } else {
    int t = dice[3];
    dice[3] = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = t;
  }
  
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  cin >> x >> y >> k;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }

  for(int i=0;i<k;i++){
    int dir;
    cin >> dir;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || ny < 0 || nx >= n || ny >=m) continue;

    x = nx;
    y = ny;
    
    roll(dir);
    if(a[x][y] == 0) a[x][y] = dice[5];
    else{
      dice[5] = a[x][y];
      a[x][y] = 0;
    }
    
    cout << dice[3] << "\n";

  }

  
  
}