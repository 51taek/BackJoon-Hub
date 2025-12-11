#include <bits/stdc++.h>
using namespace std;

int n;
int a[3];
int dp[3], mp[3];
int tmp_dp[3], tmp_mp[3];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int j=0; j<3; j++){
        cin >> a[j];
        dp[j] = mp[j] = a[j]; 
    }

    for(int i=1; i<n; i++){
        cin >> a[0] >> a[1] >> a[2];

        tmp_dp[0] = max(dp[0], dp[1]) + a[0];
        tmp_dp[1] = max({dp[0], dp[1], dp[2]}) + a[1];
        tmp_dp[2] = max(dp[1], dp[2]) + a[2];

        tmp_mp[0] = min(mp[0], mp[1]) + a[0];
        tmp_mp[1] = min({mp[0], mp[1], mp[2]}) + a[1];
        tmp_mp[2] = min(mp[1], mp[2]) + a[2];

        for(int j=0; j<3; j++){
            dp[j] = tmp_dp[j];
            mp[j] = tmp_mp[j];
        }
    }

    int ma = max({dp[0], dp[1], dp[2]});
    int mi = min({mp[0], mp[1], mp[2]});

    cout << ma << " " << mi;
}
