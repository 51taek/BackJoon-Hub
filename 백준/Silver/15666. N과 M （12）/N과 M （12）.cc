#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10];
int b[10];

void func(int idx, int st){
  if(idx == m){
    for(int i=0;i<m;i++){
      cout << b[i] << " ";
    }
    cout << "\n";
    return ;
  }

  int prev = -1;
  for(int i=st;i<n;i++){
    if(prev == a[i]) continue;
    b[idx] = a[i];
    prev = a[i];
    func(idx+1,i);
  }
  
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a, a+n);
  
  func(0,0);

  return 0;
}