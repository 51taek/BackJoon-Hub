#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;

    int dis = y - x;

    long long n = sqrt(dis);

    if(n * n == dis){
      cout << 2 * n - 1 << "\n";
    } else if(n * n + n >= dis){
      cout << 2 * n << "\n";
    } else {
      cout << 2 * n + 1 << "\n";
    }
  }
  


}