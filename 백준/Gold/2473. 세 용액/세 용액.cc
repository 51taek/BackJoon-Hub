#include <bits/stdc++.h>
using namespace std;

int n;
long long a[5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    long long min_diff = 4000000000LL; 
    long long ans[3];

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;

        int st = i + 1;
        int en = n - 1;

        while (st < en) {
            long long sum = a[i] + a[st] + a[en];
            long long abs_sum = (sum < 0) ? -sum : sum;

            if (abs_sum < min_diff) {
                min_diff = abs_sum;
                ans[0] = a[i];
                ans[1] = a[st];
                ans[2] = a[en];
            }

            if (sum < 0) {
                st++;
            } else if (sum > 0) {
                en--;
            } else {
                cout << a[i] << " " << a[st] << " " << a[en] << "\n";
                return 0;
            }
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    return 0;
}