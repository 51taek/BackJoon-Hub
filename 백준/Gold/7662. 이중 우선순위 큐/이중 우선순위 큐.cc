#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  
    for(int i=0;i<n;i++){
      cin >> m;

      priority_queue<ll> maxpq;
      priority_queue<ll, vector<ll>, greater<ll>> minpq;
      map<ll, int> cnt;

      for(int j=0;j<m;j++){
        char a; ll b;
        cin >> a >> b;

        if(a == 'I'){
          minpq.push(b);
          maxpq.push(b);
          cnt[b]++;
        } 
        else if (a == 'D'){
          if(cnt.empty()) continue;

          if(b == 1){
            while(!maxpq.empty()){
              ll v = maxpq.top();
              auto it = cnt.find(v);
              if(it != cnt.end()){
                it->second--;
                if(it->second == 0) cnt.erase(it);
                maxpq.pop();
                break;
              }
              maxpq.pop();
            }
          }
          else{
            while(!minpq.empty()){
              ll v = minpq.top();
              auto it = cnt.find(v);
              if(it != cnt.end()){
                it->second--;
                if(it->second == 0) cnt.erase(it);
                minpq.pop();
                break;
              }
              minpq.pop();
            }
          }
        }
      }
    
      while(!maxpq.empty()){
        if(cnt.find(maxpq.top()) != cnt.end()) break;
        maxpq.pop();
      }
      while(!minpq.empty()){
        if(cnt.find(minpq.top()) != cnt.end()) break;
        minpq.pop();
      }

    if(cnt.empty()) cout << "EMPTY\n";
    else cout << maxpq.top() <<" " << minpq.top() << "\n";
  } 
}