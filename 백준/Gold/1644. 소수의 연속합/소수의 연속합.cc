#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> primes;

void seive(int n) {
    vector<bool> state(n + 1, true);
    state[0] = state[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            state[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (state[i]) primes.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    seive(n);

    int ans = 0;
    int en = 0;
    int tot = 0;

    for (int st = 0; st < primes.size(); st++) {
        while (en < primes.size() && tot < n) {
            tot += primes[en++];
        }

        if (tot == n) ans++;
        tot -= primes[st];
    }

    cout << ans;
}
