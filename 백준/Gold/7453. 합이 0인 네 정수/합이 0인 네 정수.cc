#include <bits/stdc++.h>
using namespace std;

int n;
int a[4005][4];

vector<int> ab;
vector<int> cd;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ab.push_back(a[i][0] + a[j][1]);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cd.push_back(a[i][2] + a[j][3]);
    }
  }

  sort(ab.begin(), ab.end());
  sort(cd.begin(), cd.end());

  int st = 0;
  int en = ab.size()-1;
  long long ans = 0;

  while(st < ab.size() && en >= 0){

    long long sum = (long long)ab[st] + cd[en];

    if(sum == 0){
      long long aVal = ab[st];
      long long bVal = cd[en];

      long long aCnt = 0;
      long long bCnt = 0;

      while(st < ab.size() && ab[st] == aVal){
        st++;
        aCnt++;
      }

      while(en >= 0 && cd[en] == bVal){
        en--;
        bCnt++;
      }

      ans += aCnt * bCnt;
    }
    else if(sum < 0){
      st++;
    }
    else{
      en--;
    }
    
  }

  

  cout << ans;

  
}