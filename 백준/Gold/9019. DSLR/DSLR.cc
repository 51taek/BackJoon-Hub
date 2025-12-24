#include <bits/stdc++.h>
using namespace std;

int t;
int visited[10000];

#define X first
#define Y second

int D(int n){
  return (2 * n) % 10000;
}

int S(int n){
  if(n==0) return 9999;
  else return n-1;
}

int L(int n){
  int a = n / 1000;
  return (n % 1000) * 10 + a;
}

int R(int n){
  int a = n % 10;
  return (n / 10) + a * 1000;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  for(int i=0;i<t;i++){
    int a, b;
    cin >> a >> b;
    
    queue<pair<int,string>> q;
    
    fill(visited, visited + 10000, 0);
    
    visited[a] = 1;
    q.push({a,""});
    while(!q.empty()){
      auto cur = q.front(); q.pop();

      if(cur.X == b){
        cout << cur.Y << "\n";
        break;
      }

      int d = D(cur.X);
      if(!visited[d]){
        q.push({d,cur.Y+'D'});
        visited[d] = 1;
      }

      int s = S(cur.X);
      if(!visited[s]){
        q.push({s,cur.Y+'S'});
        visited[s] = 1;
      }

      int l = L(cur.X);
      if(!visited[l]){
        q.push({l,cur.Y+'L'});
        visited[l] = 1;
      }

      int r = R(cur.X);
      if(!visited[r]){
        q.push({r,cur.Y+'R'});
        visited[r] = 1;
      }
    }

  }

}