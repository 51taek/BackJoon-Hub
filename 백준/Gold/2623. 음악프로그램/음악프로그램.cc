#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[1005];
int indeg[1005];
vector<int> adj[1005];
vector<int> ans;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int k;
    cin >> k;
    cin >> input[0];
    for(int j=1;j<k;j++){
      cin >> input[j];
      adj[input[j-1]].push_back(input[j]);
      indeg[input[j]]++;
    }
  }

  queue<int> q;

  for(int i=1;i<=n;i++){
    if(indeg[i] == 0) q.push(i);
  }

  while(!q.empty()){
    int cur = q.front(); q.pop();
    ans.push_back(cur);
    for(int nxt: adj[cur]){
      indeg[nxt]--;
      if(indeg[nxt] == 0) q.push(nxt);
    }
  }

  if(ans.size() != n){
    cout << 0;
    return 0;
  }

  for(int i=0;i<ans.size();i++){
    cout << ans[i] << "\n";
  }
  
  

  
  
}