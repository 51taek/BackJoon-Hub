#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int,int>> g[55];
int dist[55];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    fill(dist,dist+N+1, 1e9);

    for(int i=0;i<road.size();i++){
        int x = road[i][0];
        int y = road[i][1];
        int cost = road[i][2];
        
        g[x].push_back({cost,y});
        g[y].push_back({cost,x});
    }
    
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
    
    pq.push({0,1});
    dist[1] = 0;
    
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        
        if(dist[cur.Y] != cur.X) continue;
        
        for(auto nxt: g[cur.Y]){
            if(dist[nxt.Y] > dist[cur.Y] + nxt.X){
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y],nxt.Y});
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(dist[i] <= K){
            answer++;
        }
    }
    

    return answer;
}