#include <bits/stdc++.h>
using namespace std;

int t;
int indegree[1005];
int d[1005];
int ans[1005];
vector<int> g[1005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    queue<int> q;
    fill(ans,ans + n + 1, 0);
    fill(indegree, indegree + n + 1, 0);
    for(int i=1;i<=n;i++){
      g[i].clear();
    }


    for(int i=1;i<=n;i++){
      cin >> d[i];
    }

    for(int i=0;i<k;i++){
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      indegree[b]++;
    }

    int dir;
    cin >> dir;

    for(int i=1;i<=n;i++){
      if(indegree[i] == 0){
        ans[i] = d[i];
        q.push(i);
      }
    }

    while(!q.empty()){
      int cur = q.front(); q.pop();

      for(int nxt: g[cur]){
        ans[nxt] = max(ans[nxt], ans[cur] + d[nxt]);
        
        indegree[nxt]--;
        if(indegree[nxt] == 0) q.push(nxt);
      }
    }

    cout << ans[dir] << "\n";
  }
}
