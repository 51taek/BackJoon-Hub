#include <bits/stdc++.h>
using namespace std;

int n;
int p[55];

void func(int c){
  p[c] = -2;

  for(int i=0;i<n;i++){
    if(p[i] == c){
      func(i);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> p[i];
  }

  int cut;
  cin >> cut;

  func(cut);
  
  int cnt = 0;
  for(int i=0;i<n;i++){
    if(p[i] == -2) continue;

    bool isLeaf = true;
    for(int j=0;j<n;j++){
      if(p[j] == i){
        isLeaf = false;
        break;
      }
    }
    if(isLeaf) cnt++;
  }

  cout << cnt;

  
}