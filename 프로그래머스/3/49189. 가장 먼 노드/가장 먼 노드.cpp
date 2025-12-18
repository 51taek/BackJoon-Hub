#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[20005];
int dist[20005];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0;i<edge.size();i++){
        int x = edge[i][0];
        int y = edge[i][1];
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    fill(dist, dist+n+1, -1);
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(int nxt: adj[cur]){
            if(dist[nxt] != -1 ) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    int mx = *max_element(dist, dist+n+1);
    answer = count(dist, dist+n+1 , mx);
    
    return answer;
}