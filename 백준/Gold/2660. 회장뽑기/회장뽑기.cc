#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int dist[100];
int score[100];

int n;

int bfs(int st){

  fill(dist, dist+n+1, -1);
  queue<int> q;
  q.push(st);
  dist[st]=0;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int i=1;i<=n;i++){
      if(a[cur][i] == 0 || dist[i] != -1) continue;
      q.push(i);
      dist[i] = dist[cur] + 1;
    }
  }

  int val = *max_element(dist + 1, dist+n+1);
  if(val == 0) return 100;
  return val;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  while (true) {
    int x, y;
    cin >> x >> y;
    if (x == -1 && y == -1) break;
    a[x][y] = 1;
    a[y][x] = 1;
  }

  for(int i=1;i<=n;i++){
    score[i] = bfs(i);
  }

  vector<int> v;

  int ans_sc = *min_element(score+1, score+n+1);

  for(int i=1;i<=n;i++){
    if(ans_sc == score[i]){
      v.push_back(i);
    }
  }

  

  cout << ans_sc << " " << v.size() << "\n";
  for(int i=0;i<v.size();i++){
    cout << v[i] << " ";
  }
  
}