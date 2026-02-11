#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a, a+n);
  vector<int> v;

  for(int i=0;i<n;i++){
    if(i+1 < n && a[i] < 0 && a[i+1] <= 0){
      v.push_back(a[i] * a[i+1]);
      i++;
    } 
    else if(a[i] <= 0){
      v.push_back(a[i]);
    } 
    else break;
  }

  for(int i=n-1;i>=0;i--){
    if(i-1 >= 0 && a[i] > 1 && a[i-1] > 1){
      v.push_back(a[i] * a[i-1]);
      i--;
    }
    else if(a[i] > 0){
      v.push_back(a[i]);
    }
    else break;
  }

  int ans = 0;
  for(int i=0;i<v.size();i++){
    ans += v[i];
  }

  cout << ans;

  
}