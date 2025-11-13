#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> v;

  cin >> n >> m;

  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int en = 0;
  int mn = 0x7fffffff;

  sort(v.begin(),v.end());

  for(int st=0; st<n; st++){
    while(en < n && v[en] - v[st] < m) en++;

    if(en == n) break;
    mn = min(mn, v[en] - v[st]);
    
  }

  cout << mn;

  

  
}