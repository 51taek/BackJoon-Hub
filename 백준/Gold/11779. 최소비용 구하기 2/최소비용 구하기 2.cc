#include <bits/stdc++.h>
using namespace std;

int n, m;
int st, en;

#define X first
#define Y second

vector<pair<int,int>> g[1005];
vector<int> cs;
int d[1005];
int p[1005];

const int INF = 0x3f3f3f3f;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({cost,y});
  }

  cin >> st >> en;

  fill(d, d+1005, INF);
  fill(p, p+1005, -1);

  priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>> > pq;

  d[st] = 0;
  pq.push({d[st],st});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(cur.X != d[cur.Y]) continue;
        
    for(auto nxt: g[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      
      d[nxt.Y] = d[cur.Y] + nxt.X;
      p[nxt.Y] = cur.Y;
      pq.push({d[nxt.Y],nxt.Y});
    }
  }

  vector<int> ans;

  int cu = en;
  while(cu != -1){
    ans.push_back(cu);
    cu = p[cu];
  }

  reverse(ans.begin(), ans.end());

  cout << d[en] << "\n";
  cout << ans.size() << "\n";
  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
  
  
}