#include <bits/stdc++.h>
using namespace std;

int n;
long long weight[30];

int used[10];
int alpha[30];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    string s;
    cin >> s;

    int p = 1;
    for(int j=s.size()-1;j>=0;j--){
      weight[s[j]-'A'] += p;
      p *= 10;
    }
  }

  vector<long long> w;
  for(int i=0;i<26;i++){
    if(weight[i] > 0) w.push_back(weight[i]);
  }

  sort(w.begin(), w.end(), greater<>());

  int num = 9;
  long long answer = 0;

  for(long long x : w){
    answer += x * num;
    num--;
  }

  cout << answer;
  
}