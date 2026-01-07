#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int,int>> v;
int bag[300005];

#define X first
#define Y second

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    v.push_back({x,y});
  }

  for(int i=0;i<k;i++){
    cin >> bag[i];
  }

  sort(bag, bag + k);
  sort(v.begin(), v.end());

  long long ans = 0;
  int idx = 0;
  priority_queue<int> pq;

  for(int i=0;i<k;i++){
    while(idx < n && v[idx].X <= bag[i]){
      pq.push(v[idx].Y);
      idx++;
    }

    if(!pq.empty()){
      ans += pq.top();
      pq.pop();
    }
    
  }

  cout << ans;
  
}