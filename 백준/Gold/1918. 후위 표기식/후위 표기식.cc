#include <bits/stdc++.h>
using namespace std;

string s;

int pri(char c){
  if(c == '*' || c == '/') return 2;
  else return 1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  stack<char> st;

  cin >> s;

  for(auto ch: s){

    if(ch >= 'A' && ch <= 'Z'){
      cout << ch;
    } else if(ch == '('){
      st.push(ch);
    } else if(ch == ')'){
        while (!st.empty() && st.top() != '(') {
          cout << st.top();
          st.pop();
        }
        st.pop();
    } else{
      while (!st.empty() && st.top() != '(' && pri(st.top()) >= pri(ch)) {
        cout << st.top();
        st.pop();
      }
      
      st.push(ch);
    }
  }

  while(!st.empty()){
    cout << st.top();
    st.pop();
  }

}