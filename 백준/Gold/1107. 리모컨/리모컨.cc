#include <bits/stdc++.h>
using namespace std;

int dir;
int m;
int a[20];

int check(int n){
  if(n == 0){
    if(a[0] == 1) return 0;
    else return 1;
  }

  int len = 0;

  while(n > 0){
    if(a[n%10] == 1) return 0;
    len++;

    n /= 10;
  }
  return len;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> dir >> m;

  for(int i=0;i<m;i++){
    int c;
    cin >> c;
    a[c] = 1;
  }

  int ans = abs(dir - 100);

  for(int i=0;i<10000000;i++){
    int len = check(i);
    if(len > 0){
      int press = len + abs(i - dir);
      ans = min(ans, press);
    }
  }

  cout << ans;
  return 0;
  
}