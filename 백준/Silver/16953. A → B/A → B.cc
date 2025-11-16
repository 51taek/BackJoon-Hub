#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    int cnt = 1;  

    while (n < m) {
        cnt++;

        if (m % 10 == 1) {
            m /= 10;          
        } else if (m % 2 == 0) {
            m /= 2;           
        } else {
            cout << -1;
            return 0;
        }
    }

    if (n == m) cout << cnt;
    else cout << -1;
}
