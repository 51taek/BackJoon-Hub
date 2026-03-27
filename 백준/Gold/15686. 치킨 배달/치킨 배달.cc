#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> home;
vector<pair<int,int>> chicken;


#define X first
#define Y second

int n, m;

int a[53][53];

int main(){
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie(0);

  cin >> n>> m;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      cin >> a[i][j];
      if(a[i][j] == 1) home.push_back({i,j});
      if(a[i][j] == 2) chicken.push_back({i,j});
    }

  vector<int> brute(chicken.size(), 1);
  fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
  int mn = 1e9;

  do{
    int dist = 0;
    for(auto h: home){
      int tmp = 1e9;
      for(int i=0;i<chicken.size();i++){
        if(brute[i] == 0) continue;
        int d = abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y);
        tmp = min(tmp, d);
      }
      dist += tmp;
    }

    mn = min(mn, dist);
    
  }while(next_permutation(brute.begin(), brute.end()));

  
  cout << mn;
  
}