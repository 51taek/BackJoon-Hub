#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100005];
long long d[100005];

int n, m, k;

#define X first
#define Y second

const long long INF = 1e15;

void solve(const vector<int>& centers){
  fill(d, d+100005,INF);

  priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>> > pq;

  for(int st : centers) {
    d[st] = 0;
    pq.push({0, st});
  }

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue;

    for(auto nxt: adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }

  int dosi; int maxN = 0;
  for(int i=0;i<n;i++){
    if(maxN < d[i]){
      dosi = i;
      maxN = d[i];
    }
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for(int i=0;i<m;i++){
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[v].push_back({cost,u});
  }

  vector<int> centers(k);
  for(int i=0; i<k; i++) cin >> centers[i];

  solve(centers);

  int ans_dosi = 0;
  long long max_dist = -1;

  for(int i=1; i<=n; i++){
    if(d[i] != INF && d[i] > max_dist){
      max_dist = d[i];
      ans_dosi = i;
    }
  }

  cout << ans_dosi << "\n" << max_dist;
  

  
}