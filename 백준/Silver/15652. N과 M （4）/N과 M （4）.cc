#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void loop(int idx){

  if(idx==m){
    for(int i=0;i<m;i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
    return ;
  }

  int st = 1;
  if(idx != 0) st = arr[idx-1];

  for(int i=st;i<=n;i++){
    arr[idx] = i;
    loop(idx+1);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);;
  cout.tie(0);

  cin >> n >> m;

  loop(0);
  
}