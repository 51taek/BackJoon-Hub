#include <bits/stdc++.h>
using namespace std;

int n;

#define X first
#define Y second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  stack<pair<int,int>> s;

  for(int i=1;i<=n;i++){
    int x;
    cin >> x;

    while(!s.empty() && s.top().X < x){
      s.pop();
    }

    if(s.empty()){
      cout << 0 << " ";
    } else {
      cout << s.top().Y << " ";
    }
    s.push({x,i});
  }

  
}