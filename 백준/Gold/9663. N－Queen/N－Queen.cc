#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;

int isused1[40];
int isused2[40];
int isused3[40];

void queen(int idx){
  if(idx == n){
    cnt++;
    return;
  }

  for(int i=0;i<n;i++){
    if(isused1[i] || isused2[idx+i] || isused3[idx - i + n - 1]) continue;
    
    isused1[i] = 1;
    isused2[idx+i] = 1;
    isused3[idx - i + n - 1] = 1;
    queen(idx+1);
    isused1[i] = 0;
    isused2[idx+i] = 0;
    isused3[idx - i + n - 1] = 0;
    
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  queen(0);

  cout << cnt;
}