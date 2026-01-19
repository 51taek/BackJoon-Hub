#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[20];
char b[20];

unordered_set<char> s = {'a', 'i', 'e', 'o', 'u'};

void func(int idx, int start){
  if(idx==n){
    bool v = false;
    int c = 0;

    for(int i=0;i<n;i++){
      if(s.count(b[i])){
        v = true;
      } else {
        c++;
      }
    }

    if (v >= 1 && c >= 2) {
      for (int i = 0; i < n; i++) cout << b[i];
      cout << '\n';
    }
    return;
  }
  
  for (int i = start; i < m; i++) {
      b[idx] = a[i];
      func(idx + 1, i + 1); 
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    cin >> a[i];
  }

  sort(a,a+m);
  
  func(0,0);
}