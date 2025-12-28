#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while(t--){
    int n;
    cin >> n;
    map<string,int> m;
    for(int i=0;i<n;i++){
      string name, type;
      cin >> name >> type;
      m[type]++;
    }

    int ans = 1;
    for(auto a: m){
      ans *= a.second + 1;
    }
    cout << ans - 1 << "\n";
    
  }
  
}