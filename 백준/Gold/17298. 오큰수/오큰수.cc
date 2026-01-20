#include <bits/stdc++.h>
using namespace std;

int n;

int ans[1000005];
int a[1000005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  stack<int> s;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  fill(ans, ans + n + 1, -1);

  for(int i=0;i<n;i++){
    while(!s.empty() &&  a[s.top()] < a[i]){
      ans[s.top()] = a[i];
      s.pop();
    }
    s.push(i);
  }

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
  
}