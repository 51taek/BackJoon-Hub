#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> v;

void func(long long num, int last){
    v.push_back(num); 

    for(int i = 0; i < last; i++){
        func(num * 10 + i, i);
    }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<=9;i++){
    func(i, i);
  }

  sort(v.begin(), v.end());

  if(n >= v.size()) cout << -1;
  else cout << v[n];

  

  
}