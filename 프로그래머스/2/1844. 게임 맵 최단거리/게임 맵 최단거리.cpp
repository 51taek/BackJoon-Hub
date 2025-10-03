#include<vector>
#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[105][105]; 

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dist[i][j] = -1;
        }
    }
    
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(dist[nx][ny] != -1 || maps[nx][ny] == 0) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    
    answer = dist[n-1][m-1];
    return answer;
}