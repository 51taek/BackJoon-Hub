#include <bits/stdc++.h>
using namespace std;

int t;
int a[100005];
int vis[100005];
int done[100005];
vector<int> v;
int ans;


void dfs(int idx){
  vis[idx] = 1;
  v.push_back(idx);

  int nxt = a[idx];

  if(!vis[nxt]){
    dfs(nxt);
  }
  else if(!done[nxt]){
    // 사이클 발견
    for(int i = v.size() - 1; i >= 0; i--){
      ans++;
      if(v[i] == nxt) break;
    }
  }

  done[idx] = 1;
  v.pop_back();
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while(t--){

    int n;
    ans = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      vis[i] = 0;
      done[i] = 0;
      
    }

    for(int i=1;i<=n;i++){
      if(!vis[i]){
        v.clear();
        dfs(i);
      }
    }
  

    cout << n - ans << "\n";
    
  }
}