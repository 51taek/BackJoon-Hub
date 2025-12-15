#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int a, b;

const int INF = 0x3f3f3f3f;

vector<pair<int,int>> graph[1000];
int d[1000];

long long mini(int st, int en){
  priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>> > pq;

  fill(d, d + n + 1, INF);
  
  d[st] = 0;
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue;

    for(auto nxt: graph[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }
  return d[en];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;


  for(int i=0;i<m;i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    graph[x].push_back({cost,y});
    graph[y].push_back({cost,x});
  }

  cin >> a >> b;

  long long ans1 = mini(1,a) + mini(a,b) + mini(b,n);
  long long ans2 = mini(1,b) + mini(b,a) + mini(a,n);

  long long ans = min(ans1,ans2);
  if(ans >= INF) ans = -1;
  cout << ans;
  
}