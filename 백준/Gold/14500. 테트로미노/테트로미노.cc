#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[502][502];
int vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int maxN = 0;

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        maxN = max(maxN, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (vis[nx][ny]) continue;

        vis[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        vis[nx][ny] = false;  
    }
}

void checkT(int x, int y) {
    int center = board[x][y];
    vector<int> arms;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        arms.push_back(board[nx][ny]);
    }

    if (arms.size() < 3) return;

    sort(arms.begin(), arms.end(), greater<int>());
    int sum = center + arms[0] + arms[1] + arms[2];
    maxN = max(maxN, sum);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vis[i][j] = true;
      dfs(i, j, 1, board[i][j]);  
      vis[i][j] = false;

      checkT(i,j); 
    }
  }

  cout << maxN;
  return 0;
}