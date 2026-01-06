#include <bits/stdc++.h>
using namespace std;

int n;
long long a[5005];

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
  long long x, y, z;

  for(int i=0;i<n-2;i++){
    if (i > 0 && a[i] == a[i-1]) continue;
    long long fix = a[i];

    int st = i + 1;
    int en = n - 1;

    while(st < en){
      long long sum = a[st] + a[en] + fix;
      long long abs_sum = (sum < 0) ? -sum : sum;

      if (llabs(sum) < m) {
        
          m = abs_sum;
          x = fix;
          y = a[st];
          z = a[en];
      }

      if(sum < 0) st++;
      else if(sum > 0) en--;
      else {
          cout << fix << " " << a[st] << " " << a[en];
          return 0;
      }
      
    }
    
  }

  cout << x << " " << y << " " << z;
}