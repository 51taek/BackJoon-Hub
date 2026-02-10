#include <bits/stdc++.h>
using namespace std;

int t;

#define X first
#define Y second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while(t--){
    int n;
    cin >> n;

    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
      int x, y;
      cin >> x >> y;
      v.push_back({x,y});
    }

    sort(v.begin(), v.end());

    int pass = 0;
    int minY = v[0].Y;

    for(int i=0;i<n;i++){
      if(minY < v[i].Y) pass++;
      else minY = v[i].Y;
    }

    cout << n - pass << "\n";
  }

  
}