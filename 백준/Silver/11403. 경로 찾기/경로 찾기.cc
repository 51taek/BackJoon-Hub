#include <bits/stdc++.h>
using namespace std;

int n;
int graph[102][102];
int ans[102][102];
bool visited[102];

void dfs(int start, int now) {
    for (int i = 0; i < n; i++) {
        if (graph[now][i] == 1 && !visited[i]) {
            visited[i] = true;
            ans[start][i] = 1;   
            dfs(start, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    for (int i = 0; i < n; i++) {
        fill(visited, visited + n, false); 
        dfs(i, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}
