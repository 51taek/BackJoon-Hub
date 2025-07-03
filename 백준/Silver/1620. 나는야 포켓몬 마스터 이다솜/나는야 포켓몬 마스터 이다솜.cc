#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int n, m;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  string s;
  map<int,string> m1;
  map<string, int>m2;

  for(int i=0;i<n;i++){
    cin >> s;
    m1.insert({i,s});
    m2.insert({s,i});
  }

  for(int i=0;i<m;i++){
    string a;
    cin >> a;
    if (isNumber(a)) {
      int b = stoi(a);
      cout << m1[b-1] << "\n";
    } else {
      cout << m2[a] + 1 << "\n";
    }
  }
  
}