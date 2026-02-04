#include <bits/stdc++.h>
using namespace std;

int top[4][10];

void rotation(int t, int dir){
  if(dir == 1){
    int temp = top[t][8];
    for(int i = 8; i >= 2; i--) top[t][i] = top[t][i-1];
    top[t][1] = temp;
  }
  else if(dir == -1){
    int temp = top[t][1];
    for(int i = 1; i <= 7; i++) top[t][i] = top[t][i+1];
    top[t][8] = temp;
  }
}

void move(int t, int c){

  int dirs[4] = {0};
  dirs[t] = c;

  for (int i = t; i < 3; i++) { 
    if (top[i][3] != top[i + 1][7]) {
        dirs[i + 1] = -dirs[i];
    } else break;
  }

  for (int i = t; i > 0; i--) {
    if (top[i][7] != top[i - 1][3]) {
        dirs[i - 1] = -dirs[i];
    } else break;
  }

  for(int i=0;i<4;i++){
    rotation(i,dirs[i]);
  }
  
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i=0;i<4;i++){
    string s; cin >> s; 
    for(int j=1; j<=8; j++){
        top[i][j] = s[j-1] - '0';
    }
  }

  int n;
  cin >> n;

  for(int i=0;i<n;i++){
    int t, c;
    cin >> t >> c;
    move(t-1,c);
  }

  int ans = 0;
  int score = 1;
  for(int i=0;i<4;i++){
    if(top[i][1] == 1) ans += score;
    score *= 2;
  }

  cout << ans;
  
}