#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  map<int, int> m;

  for (int i = 1; i <= 20; i++) {
      m.insert(make_pair(i, 0));
  }

  cin >> n;
  string a;
  int b;

  for(int i=0;i<n;i++){
    cin >> a;
    if(a=="all"){
      for(int j=1;j<=20;j++){
        m[j] = 1;
      }
    } else if(a=="empty"){
      for(int t=1;t<=20;t++){
        m[t] = 0;
      } 
    } else {
      cin >> b;
      if(a=="add"){
        m[b] = 1;
      } else if(a=="remove"){
        m[b] = 0;
      } else if(a=="check"){
        cout << m[b] << "\n";
      } else if(a=="toggle"){
        m[b] = abs(m[b]-1);
      } else if(a=="empty"){
        for(int t=1;t<=20;t++){
          m[t] = 0;
        } 
      } else {
        continue;
      }
    }
  }

  
}