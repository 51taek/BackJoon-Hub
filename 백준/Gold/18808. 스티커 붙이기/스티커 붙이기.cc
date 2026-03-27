#include <bits/stdc++.h>
using namespace std;

int note[42][42];
int paper[12][12];

int n, m, k;
int r, c;

void rotate(){

  int tmp[12][12];

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      tmp[i][j] = paper[i][j];
    }
  }

  for(int i=0;i<c;i++){
    for(int j=0;j<r;j++){
      paper[i][j] = tmp[r-1-j][i];
    }
  }

  swap(r,c);
}

bool paste(int x, int y){

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(note[x+i][y+j] == 1 && paper[i][j] == 1) return false;
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(paper[i][j] == 1){
        note[x+i][y+j] = 1;
      }
    }
  }

  return true;
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;

  while(k--){

    cin >> r >> c;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin >> paper[i][j];
      }
    }

    for(int rot=0;rot<4;rot++){
      bool is_paste = false;
      for(int x=0;x<=n-r;x++){
        for(int y=0;y<=m-c;y++){
          if(paste(x,y)){
            is_paste = true;
            break;
          }
        }
        if(is_paste) break;
      }
      if(is_paste) break;
      rotate();
    }
  }

  int ans = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(note[i][j] == 1) ans++;


  cout << ans;

  
}