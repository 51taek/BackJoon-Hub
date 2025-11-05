#include <bits/stdc++.h>
using namespace std;

int n, m;

int board[55][55];

#define X first
#define Y second


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  vector<pair<int,int>> chicken;
  vector<pair<int,int>> home;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> board[i][j];
      if(board[i][j] == 2) chicken.push_back({i,j});
      if(board[i][j] == 1) home.push_back({i,j});
    }
  }

  vector<int> brute (chicken.size(), 1);
  fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
  int ans = INT_MAX;
  
  do{
    int dist = 0;
    for(auto h: home){
      
      int tmp = INT_MAX;
      for(int i=0;i<chicken.size();i++){
        if(brute[i] == 0) continue;
        tmp = min(tmp, (abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y)));
      }
      
      dist += tmp;
    }
    
    ans = min(ans, dist);

  } while(next_permutation(brute.begin(), brute.end()));
  
  cout << ans;

}