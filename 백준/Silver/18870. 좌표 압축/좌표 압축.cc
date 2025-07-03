#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  map<int, int> m;

  int n;
  cin >> n;
  int a[n];
  int b[n];

  for(int i=0;i<n;i++){
    cin >> a[i];
    b[i] = a[i]; 
  }

  sort(b, b+n); 

  int idx = 0;
  for(int i=0;i<n;i++){
    if(m.count(b[i]) == 0){
      m[b[i]] = idx++;
    }
  }

  for(int i=0;i<n;i++){
    cout << m[a[i]] << " ";
  }

  return 0;
}
