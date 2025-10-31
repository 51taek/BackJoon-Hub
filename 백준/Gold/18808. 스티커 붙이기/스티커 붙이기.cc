#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int board[12][12];
int note[42][42];

bool stick(int x, int y){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(board[i][j] == 1 && note[x+i][y+j] == 1)
        return false;
    }
  }
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(board[i][j] == 1)
        note[x+i][y+j] = 1;
    }
  }
  return true;
}

void rotate(){
  int tmp[12][12];
  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
      tmp[i][j] = board[i][j];

  for(int i=0;i<c;i++)
    for(int j=0;j<r;j++)
      board[i][j] = tmp[r-1-j][i];

  swap(r, c);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  while(k--){
    cin >> r >> c;
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        cin >> board[i][j];

    bool is_stick = false;

    for(int rot=0; rot<4; rot++){
      for(int x=0; x<=n-r; x++){
        if(is_stick) break;
        for(int y=0; y<=m-c; y++){
          if(stick(x, y)){
            is_stick = true;
            break;
          }
        }
      }
      if(is_stick) break;
      rotate();
    }
  }

  int ans = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      ans += note[i][j];

  cout << ans;
}
