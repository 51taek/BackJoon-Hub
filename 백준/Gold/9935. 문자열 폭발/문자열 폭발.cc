#include <bits/stdc++.h>
using namespace std;

string s;
string bomb;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> bomb;

  char last = bomb[bomb.size()-1];

  vector<char> v;

  for(char c: s){
    v.push_back(c);
    if(c == last && v.size() >= bomb.size()){
      bool chk = true;
      int n = v.size()-1;
      for(int i=bomb.size()-1; i>=0; i--){
        if(bomb[i] != v[n]) chk = false;
        n--;
      }

      if(chk){
        v.resize(v.size() - bomb.size());
      }
    }
  }

  if(v.empty()){
    cout << "FRULA";
    return 0;
  }
  
  for(int i=0;i<v.size();i++){
    cout << v[i];
  }
  
}