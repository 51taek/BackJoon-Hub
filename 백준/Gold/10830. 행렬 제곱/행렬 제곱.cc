#include <bits/stdc++.h>
using namespace std;

long long n, b;
long long board[10][10];

using matrix = vector<vector<long long>>;

matrix multiply(const matrix& a, const matrix& b) {
    matrix res(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;  
        }
    }
    return res;
}

matrix power(matrix A, long long b){
  if(b==1) return A;

  matrix half = power(A, b/2);
  matrix result = multiply(half,half);

  if(b % 2 == 1){
    result = multiply(result, A);
  }

  return result;
  
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;

    matrix a(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] %= 1000;
        }
    }

    matrix ans = power(a, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}