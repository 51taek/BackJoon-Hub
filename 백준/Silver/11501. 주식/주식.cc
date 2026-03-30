#include <bits/stdc++.h>
using namespace std;
int t, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];

        long long ans = 0;
        int ma = 0;
        for(int i=n-1;i>=0;i--){
            ma = max(ma, v[i]);
            ans += ma - v[i]; 
        }
        cout << ans << "\n";
    }
}