#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for(int i=0;i<clothes.size();i++){
        if(m.find(clothes[i][1]) == m.end()){
            m.insert({clothes[i][1],1});
        }else{
            m[clothes[i][1]]++;
        }
    }
    
    for(const auto& c: m){
        answer *= (c.second + 1);
    }
    
    
    
    return answer-1;
}