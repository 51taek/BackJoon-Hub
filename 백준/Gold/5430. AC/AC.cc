#include <bits/stdc++.h>
using namespace std;

int t;
deque<int> dq;

void func(string s){

  bool reverse = false;
  for(char c: s){
    
    if(c == 'R'){
      reverse = !reverse;
    } else {
      if(dq.empty()){
        cout << "error\n";
        return;
      }
      if(!reverse){
        dq.pop_front();
      } else {
        dq.pop_back();
      }
    }
  }
  
  cout << "[";
  int current_size = dq.size(); 

  if (!reverse) {
      for (int i = 0; i < current_size; i++) {
          cout << dq[i];
          if (i < current_size - 1) cout << ","; 
      }
  } else {
      for (int i = current_size - 1; i >= 0; i--) {
          cout << dq[i];
          if (i > 0) cout << ",";
      }
  }
  cout << "]\n";

  return;
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while(t--){
    string p; int n;
    string s;
    dq.clear();
    cin >> p;
    cin >> n;
    cin >> s;
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            temp += s[i];
        } else {
            if (!temp.empty()) {
                dq.push_back(stoi(temp));
                temp = "";
            }
        }
    }
    func(p);
    
  }

  
}