#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> m;
    unordered_map<string, vector<pair<int,int>>> um;
    
    vector<vector<int>> v;
    
    for(int i=0;i<genres.size();i++){
        m[genres[i]] += plays[i];
        um[genres[i]].push_back({plays[i],i});
    }
    
    
    while(!m.empty()){
        int mg = 0;
        string g;
        for(const auto& a: m){
            if(mg < a.second){
                g = a.first;
                mg = a.second;
            }
        }
        
        sort(um[g].begin(), um[g].end(), [](pair<int,int>& a, pair<int,int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        
        answer.push_back(um[g][0].second);
        if (um[g].size() > 1) answer.push_back(um[g][1].second);
        m.erase(g);
    }
    
    
    
    return answer;
}