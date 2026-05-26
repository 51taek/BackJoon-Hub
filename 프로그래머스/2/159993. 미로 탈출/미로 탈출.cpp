#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int n, m;

char board[105][105];

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y, int dix, int diy){
    int dist[105][105];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    dist[x][y] = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'X') continue;
            if(dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    
    return dist[dix][diy];
}

int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    pair<int,int> l;
    pair<int,int> st;
    pair<int,int> e;
    
    int j = 0;
    for(string s: maps){
        for(int i=0;i<s.size();i++){
            board[j][i] = s[i];
            if(s[i] == 'L') l = {j,i};
            if(s[i] == 'S') st = {j,i};
            if(s[i] == 'E') e = {j,i};
        }
        j++;
    }
    
    int stle = bfs(st.X,st.Y,l.X,l.Y);
    int leen = bfs(l.X,l.Y,e.X,e.Y);
    
    if(stle == -1 || leen == -1) return -1;
        
    return stle + leen;
}