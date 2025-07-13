#include <string>
#include <vector>

using namespace std;

vector<int> graph[102];
bool visit[102];

int dfs(int node){
    int cnt = 1;
    visit[node] = true;
    for(int n: graph[node]){
        if(visit[n]) continue;
        cnt += dfs(n);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100000000;
    
    for(int i=0;i<wires.size();i++){
        
        fill(visit, visit+102, false);
        for(int t=1;t<=n;t++){
            graph[t].clear();
        }
        
        for(int j=0;j<wires.size();j++){
            if(j==i) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        
        int cnt = dfs(1);
        int dif = abs(cnt - (n - cnt));
        answer = min(answer,dif);
    }
    
    
    return answer;
}