        #include <bits/stdc++.h>
        using namespace std;

        int m, n, h;
        int a[102][102][102];
        int vis[102][102][102];

        int dx[6] = {1, 0, -1, 0, 0, 0};
        int dy[6] = {0, 1, 0, -1, 0, 0};
        int dz[6] = {0, 0, 0, 0, 1, -1};

        int main(){
            ios::sync_with_stdio(0);
            cin.tie(0);

            cin >> m >> n >> h;

            queue<tuple<int,int,int>> q;

            for(int z=0; z<h; z++){
                for(int x=0; x<n; x++){
                    for(int y=0; y<m; y++){
                        cin >> a[x][y][z];
                        if (a[x][y][z] == 1) { 
                            q.push({x, y, z});
                            vis[x][y][z] = 0;
                        }
                        else if (a[x][y][z] == 0) {
                            vis[x][y][z] = -1; 
                        }
                    }
                }
            }

            while (!q.empty()){
              auto cur = q.front(); q.pop(); 
              int curX; 
              int curY; 
              int curZ; 
              tie(curX, curY, curZ) = cur;

                for (int dir=0; dir<6; dir++){
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];
                    int nz = curZ + dz[dir];
                    if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;

                    if (a[nx][ny][nz] == 0 && vis[nx][ny][nz] == -1) {
                        a[nx][ny][nz] = 1;
                        vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;
                        q.push({nx, ny, nz});
                    }
                }
            }

            int ans = 0;
            for(int z=0; z<h; z++){
                for(int x=0; x<n; x++){
                    for(int y=0; y<m; y++){
                        if (a[x][y][z] == 0) { // 안 익은 토마토 남음
                            cout << -1;
                            return 0;
                        }
                        ans = max(ans, vis[x][y][z]);
                    }
                }
            }

            cout << ans;
            return 0;
        }
