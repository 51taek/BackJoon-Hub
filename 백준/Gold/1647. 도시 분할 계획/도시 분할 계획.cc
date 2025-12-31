#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int,int>> g[100005];
bool chck[100005];

#define X first
#define Y second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({cost,y});
    g[y].push_back({cost,x});
  }

  priority_queue<tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>> > pq;

  
  chck[1] = 1;
  for(auto a: g[1])
    pq.push({a.X,1,a.Y});

  int cnt = 0;
  int ans = 0;
  int maxCost = 0;

  while(cnt < n-1){
    int cost, a, b;
    tie(cost, a, b) = pq.top(); pq.pop();
    maxCost = max(maxCost, cost);

    if(chck[b]) continue;
    ans += cost;
    chck[b] = 1;
    cnt++;
    for(auto nxt: g[b]){
      if(!chck[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
    }
  }

  cout << ans - maxCost;
  
}