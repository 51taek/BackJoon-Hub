#include <bits/stdc++.h>
using namespace std;

int n;
string pattern;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> pattern;
  int pi = pattern.find('*');
  string fp = pattern.substr(0,pi);
  string bp = pattern.substr(pi+1);

  for(int i=0;i<n;i++){
    string s;
    cin >> s;

    if(s.size() < fp.size() + bp.size()){
      cout << "NE\n";
      continue;
    }

    if (s.substr(0, fp.size()) == fp && 
      s.substr(s.size() - bp.size()) == bp) {
      cout << "DA\n";
    } else {
      cout << "NE\n";
    }
  }

  
}