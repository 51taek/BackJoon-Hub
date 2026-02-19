#include <string>
#include <vector>
#include <bits/stdc++.h>

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


using namespace std;

vector<pair<int,int>> normalize(vector<pair<int,int>> shape) {
    int minx = 1e9, miny = 1e9;
    
    for(auto &p : shape) {
        minx = min(minx, p.X);
        miny = min(miny, p.Y);
    }
    
    for(auto &p : shape) {
        p.X -= minx;
        p.Y -= miny;
    }
    
    sort(shape.begin(), shape.end());
    return shape;
}

vector<pair<int,int>> bfs(int sx, int sy,
                          vector<vector<int>>& board,
                          vector<vector<int>>& vis,
                          int target) {
    
    int n = board.size();
    int m = board[0].size();
    
    queue<pair<int,int>> q;
    vector<pair<int,int>> shape;
    
    q.push({sx, sy});
    vis[sx][sy] = 1;
    shape.push_back({sx, sy});
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] != target) continue;
            
            vis[nx][ny] = 1;
            q.push({nx, ny});
            shape.push_back({nx, ny});
        }
    }
    
    return normalize(shape);
}

vector<pair<int,int>> rotate(vector<pair<int,int>> shape) {
    vector<pair<int,int>> ret;
    
    for(auto &p : shape) {
        ret.push_back({p.Y, -p.X});
    }
    
    return normalize(ret);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -0;
    int n = game_board.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    
    vector<vector<pair<int,int>>> blanks;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && game_board[i][j] == 0){
                blanks.push_back(bfs(i,j,game_board,vis,0));
            }
        }
    }
    
    vis.assign(n, vector<int>(n, 0));
    
    vector<vector<pair<int,int>>> puzzles;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && table[i][j] == 1){
                puzzles.push_back(bfs(i,j,table,vis,1));
            }
        }
    }
    
    vector<bool> used(puzzles.size(), false);
    
    for(auto &blank: blanks){
        for(int i=0;i<puzzles.size();i++){
            if(used[i]) continue;
            if(puzzles[i].size() != blank.size()) continue;
            
            vector<pair<int,int>> cur = puzzles[i];
            
            bool match = false;
            
            for(int j=0;j<4;j++){
                if(blank==cur){
                    match = true;
                    break;
                }
                cur = rotate(cur);
            }
            
            if(match) {
                used[i] = true;
                answer += blank.size();
                break;
            }
        }
    }
    
    return answer;
    
}