#include <bits/stdc++.h>  
using namespace std;

int n;
int a[200005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int cnt[10] = {0};   
  int kind = 0;  
  int en = 0;
  int ans = 0;

  for (int st = 0; st < n; st++) {
    while (en < n) {
        if (cnt[a[en]] == 0 && kind == 2) break;
        if (cnt[a[en]] == 0) kind++;
        cnt[a[en]]++;
        en++;
    }

    ans = max(ans, en - st);

    cnt[a[st]]--;
    if (cnt[a[st]] == 0) kind--;
  }

  cout << ans << '\n';
  
}