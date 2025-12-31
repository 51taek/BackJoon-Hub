#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a[10][10];
vector<pair<int,int>> emp;

bool isPossible(int r, int c, int num){
  for(int i=0;i<9;i++){
    if(a[r][i] == num) return false;
    if(a[i][c] == num) return false;
  }

  int startRow = (r / 3) * 3;
  int startCol = (c / 3) * 3;

  for (int i = startRow; i < startRow + 3; i++) {
      for (int j = startCol; j < startCol + 3; j++) {
          if (a[i][j] == num) return false;
      }
  }
  return true;
}

bool func(int idx){
  if(idx == emp.size()){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout << a[i][j];
      }
      cout << "\n";
    }
    return true;
  }
  
  int r = emp[idx].X;
  int c = emp[idx].Y;

  for(int i=1;i<=9;i++){
    if(isPossible(r,c,i)){
      a[r][c] = i;
      if(func(idx+1)) return true;
      a[r][c] = 0;
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      char c;
      cin >> c;
      a[i][j] = c - '0';
      if(a[i][j] == 0) emp.push_back({i,j});
    }
  }


  func(0);
  
}