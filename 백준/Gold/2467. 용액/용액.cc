#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int st = 0;
  int en = n - 1;
  long long m = LLONG_MAX;

  sort(a, a+n);

  int ansst = 0;
  int ansen = 0;
  
  while (st < en) {
      long long sum = a[st] + a[en];

      if (llabs(sum) < m) {
          m = llabs(sum);
          ansst = a[st];
          ansen = a[en];
      }

      if (sum < 0)
          st++;
      else
          en--;
  }

  cout << ansst << " " << ansen;
  
  
}