#include <string>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

bool canChange(string a, string b){
    int diff = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) diff++;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    
    
    vector<bool> vis(words.size(), false);
    queue<pair<string,int>> q;
    
    q.push({begin,0});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        if(cur.X == target) return cur.Y;
        
        for(int i=0;i<words.size();i++){
            if(vis[i]) continue;
            
            if(canChange(words[i], cur.X)){
                q.push({words[i], cur.Y+1});
                vis[i] = 1;
            }
        }
    }
    
    return 0;
    
}