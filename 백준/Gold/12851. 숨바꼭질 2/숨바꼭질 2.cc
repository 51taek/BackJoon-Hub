#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100010];
int dist[100010];
int ways[100010];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  queue<int> q;
  map<int,int> m;
  fill(dist, dist+100005, -1);
  
  q.push(n);
  dist[n] = 0;
  ways[n] = 1;
  
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int nx: {cur+1, cur-1, cur*2}){

      if(nx < 0 || nx > 100005) continue;
      
      if (dist[nx] == -1) {
        dist[nx] = dist[cur] + 1;
        ways[nx] = ways[cur];
        q.push(nx);
      }
      else if (dist[nx] == dist[cur] + 1) {
        ways[nx] += ways[cur];
      }
    }
  }

  cout << dist[k] << "\n" << ways[k];
  
}