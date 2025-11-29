#include <bits/stdc++.h>
using namespace std;

int n;
int board[500][500];
int ans[2];

bool check(int idx, int x, int y){
  for(int i=x;i<idx+x;i++)
    for(int j=y;j<idx+y;j++)
      if(board[i][j] != board[x][y]) return false;

  return true;
}

void func(int idx, int x, int y){
  if(check(idx,x,y)){
    ans[board[x][y]]++;
    return ;
  }
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      func(idx/2, x + i*idx/2, y + j*idx/2);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> board[i][j];
    }
  }
  func(n,0,0);

  for(int i=0;i<2;i++){
    cout << ans[i] << "\n";
  }

  
}