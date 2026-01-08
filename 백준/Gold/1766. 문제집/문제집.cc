#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

priority_queue<int, vector<int>, greater<int>> adj[100005];
int in[100005];
vector<int> ans;

int n, m;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int x, y;
    cin >> x >> y;
    adj[x].push(y);
    in[y]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  for(int i=1;i<=n;i++)
    if(in[i] == 0) q.push(i);

  while(!q.empty()){
    int cur = q.top(); q.pop();
    ans.push_back(cur);
    while(!adj[cur].empty()){
      int nxt = adj[cur].top(); adj[cur].pop();
      in[nxt]--;
      if(in[nxt] == 0) q.push(nxt);
    }
  }

  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }

  
}