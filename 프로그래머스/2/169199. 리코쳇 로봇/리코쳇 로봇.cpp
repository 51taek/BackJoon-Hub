#include <string>
#include <vector>
#include <bits/stdc++.h>

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

char c[105][105];
int vis[105][105];

int solution(vector<string> board) {
    int answer = -1;
    pair<int,int> st;
    pair<int,int> en;
    
    int n = board.size();
    int m = board[0].size();
        
    int i=0;
    for(string s: board){
        for(int j=0;j<s.size();j++){
            c[i][j] = s[j];
            if(s[j] == 'G') en = {i,j};
            if(s[j] == 'R') st = {i,j};
        }
        i++;
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            vis[i][j] = -1;
    
    queue<pair<int,int>> q;
    q.push(st);
    vis[st.X][st.Y] = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur == en){
            return vis[en.X][en.Y];
        }
        
        for(int dir = 0; dir< 4;dir++){
            int nx = cur.X;
            int ny = cur.Y;
            
            while(true){
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];

                if(tx < 0 || ty < 0 || tx >= n || ty >= m) break;
                if(board[tx][ty] == 'D') break;

                nx = tx;
                ny = ty;
            }
            
            if(vis[nx][ny] != -1) continue;
            
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    
    return -1;
}