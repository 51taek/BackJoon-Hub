#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int chck[100005];

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int en = 0;
  long long ans = 0;

  for(int st = 0;st<n;st++){
    while(en < n && chck[a[en]] == 0){
      chck[a[en]]++;
      en++;
    }
    ans += (en - st);

    chck[a[st]]--;
  }

  cout << ans;
  
}