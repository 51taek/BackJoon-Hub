#include <bits/stdc++.h>
using namespace std;

string ds[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  string cro;
  cin >> cro;

  for(string s: ds){
    while(true){
      int pos = cro.find(s);
      if(pos == string::npos) break;
      cro.replace(pos, s.size(), "1");
    }
    
  }

  cout << cro.size();
  

  
}