#include <bits/stdc++.h>
using namespace std;

string a;
string b;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  getline(cin, a);
  getline(cin, b);

  int cnt = 0;

  int idx = a.find(b);
  while(idx != -1){

    cnt++;
    idx = a.find(b, idx + b.size());
  }

  cout << cnt;

  
}