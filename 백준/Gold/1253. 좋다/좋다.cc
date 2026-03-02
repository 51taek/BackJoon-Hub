#include <bits/stdc++.h>
using namespace std;

int n;
int a[2005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  int good = 0;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a, a+n);

  for(int i=0;i<n;i++){
    int tar = a[i];
    int st = 0;
    int en = n-1;

    while(st<en){
      if(st == i){
        st++;
        continue;
      }
      if(en == i){
        en--;
        continue;
      }

      long long sum = a[st] + a[en];
      if(sum == tar){
        good++;
        break;
      } else if(sum < tar){
        st++;
      } else if(sum > tar){
        en--;
      }
      
    }
    
  }

  cout << good;

  

  
}