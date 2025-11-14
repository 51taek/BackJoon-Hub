#include <bits/stdc++.h>
using namespace std;

int lc[50];
int rc[50];
int n;
char p, l, r;

void preorder(int n){
  cout << char('A' + n);
  if(lc[n] != -1) preorder(lc[n]);
  if(rc[n] != -1) preorder(rc[n]);
}

void postorder(int n){
  if(lc[n] != -1) postorder(lc[n]);
  if(rc[n] != -1) postorder(rc[n]);
  cout << char('A' + n);
}

void middleorder(int n){
  if(lc[n] != -1) middleorder(lc[n]);
  cout << char('A' + n);
  if(rc[n] != -1) middleorder(rc[n]);
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> p >> l >> r;
    int idx = p - 'A';
    lc[idx] = (l == '.' ? -1 : l - 'A');
    rc[idx] = (r == '.' ? -1 : r - 'A');
  }

  preorder(0);
  cout << "\n";
  middleorder(0);
  cout << "\n";
  postorder(0);
  

  return 0;
}