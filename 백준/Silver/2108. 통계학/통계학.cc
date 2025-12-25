#include <bits/stdc++.h>
using namespace std;

int n;
int a[500002];
int cnt[8001];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int sum = 0;
  int maxN = -4000;
  int minN = 4000;

  for(int i=0;i<n;i++){
    cin >> a[i];
    sum += a[i];
    cnt[a[i] + 4000]++;
    maxN = max(maxN, a[i]);
    minN = min(minN, a[i]);
  }

  int maxFreq = 0;
  for(int i=0;i<=8000;i++)
    maxFreq = max(maxFreq, cnt[i]);

  bool first = true;
  int mode;
  for(int i=0;i<=8000;i++){
    if(cnt[i] == maxFreq){
      if(first){
        mode = i - 4000;
        first = false;
      } else {
        mode = i - 4000;
        break;
      }
    }
  }

  sort(a, a+n);

  cout << (int)round((double)sum / n) << "\n";
  cout << a[n/2] << "\n";
  cout << mode << "\n";
  cout << maxN - minN << "\n";
}
