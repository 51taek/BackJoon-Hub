#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int b[1000005];     
int cnt[1000005];   

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    cnt[a[i]]++;
  }

  for(int x = 1; x <= 1000000; x++){
    if(cnt[x] == 0) continue;

    for(int y = x * 2; y <= 1000000; y += x){
      if(cnt[y] == 0) continue;

      b[x]++;
      b[y]--;
    }
  }

  for(int i = 0; i < n; i++){
    cout << b[a[i]] << " ";
  }
}
