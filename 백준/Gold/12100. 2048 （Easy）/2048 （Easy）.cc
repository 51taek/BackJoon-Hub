#include <bits/stdc++.h>
using namespace std;

int n;
int a[25][25];
int b[25][25];

void rotate(){
  int tmp[25][25];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      tmp[i][j] = b[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      b[i][j] = tmp[n-1-j][i];
    }
  }
}

void move(int dir){
  while(dir--) rotate();

  for(int i=0;i<n;i++){
    int tilt[25] = {};
    int idx = 0;

    for(int j=0;j<n;j++){
      if(b[i][j] == 0) continue;
      if(tilt[idx] == 0){
        tilt[idx] = b[i][j];
      } else if(tilt[idx] == b[i][j]){
        tilt[idx++] *= 2;
      }else{
        tilt[++idx] = b[i][j];
      }
    }

    for(int j=0;j<n;j++){
      b[i][j] = tilt[j];
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }

  int mx = 0;

  for(int tmp=0;tmp<1024;tmp++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        b[i][j] = a[i][j];
      }
    }
    int brute = tmp;

    for(int i=0;i<5;i++){
      int dir = brute %4;
      brute /= 4;
      move(dir);
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        mx = max(mx, b[i][j]);
      }
    }
  }

  cout << mx;
}