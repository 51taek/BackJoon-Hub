#include <bits/stdc++.h>
using namespace std;

int n;

long long a[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a, a+n);


  long long m = LLONG_MAX;

  vector<long long> ans;

  for(int i=0;i<n;i++){
    long long st = a[i];
    int idx = lower_bound(a, a+n, -st) - a;

    if(idx < n && idx != i){
      if(m > llabs(st + a[idx])){
        m = llabs(st + a[idx]);
        ans = {st, a[idx]};
      }
    }

    if(idx-1 >= 0 && idx-1 != i){
      if(m > llabs(st + a[idx-1])){
        m = llabs(st + a[idx-1]);
        ans = {st, a[idx-1]};
      }
    }
  }

  sort(ans.begin(), ans.end());


  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
  
}