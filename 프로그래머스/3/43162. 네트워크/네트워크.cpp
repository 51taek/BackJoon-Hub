#include <string>
#include <vector>
#include <queue>

int vis[202];

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(vis[i] == 1) continue;
        
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            
            for(int j=0;j<n;j++){
                if(computers[cur][j] != 1 || vis[j]) continue;
                q.push(j);
                vis[j] = 1;
            }
        }
        answer++;
    }
    
    return answer;
}