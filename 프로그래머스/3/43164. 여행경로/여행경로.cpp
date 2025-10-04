#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool vis[1005];
vector<string> answer;
bool finished = 0;


void dfs(vector<vector<string>> &tickets, vector<string> &r, int cnt){
    if(tickets.size() == cnt){
        answer = r;
        finished = 1;
        return;
    }
    
    for(int i=0;i<tickets.size();i++){
        if(r[r.size()-1] == tickets[i][0] && vis[i] == 0){
            vis[i]=1;
            r.push_back(tickets[i][1]);
            if(finished == 1) return;
            dfs(tickets,r, cnt+1);
            r.pop_back();
            vis[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> r;
    sort(tickets.begin(), tickets.end());

    r.push_back("ICN"); 

    dfs(tickets, r, 0);
    return answer;
}