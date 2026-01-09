#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
vector<int> lis;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  lis.push_back(a[0]);
  for(int i=0;i<n;i++){
    if(lis.empty() || lis.back() < a[i]){
      lis.push_back(a[i]);
    } else {
      auto l = lower_bound(lis.begin(), lis.end(), a[i]);
      *l = a[i];
    }
  }

  cout << lis.size();
  
  
}