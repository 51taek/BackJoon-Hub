#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    
    
    for(string op: operations){
        if(op[0] == 'I'){
            int o = stoi(op.substr(2));
            ms.insert(o);
        }else if(op[0] == 'D' && op[2] == '-'){
            if(ms.empty()) continue;
            ms.erase(ms.begin());
        } else {
            if(ms.empty()) continue;
            auto m = ms.end();
            --m;
            ms.erase(m);
        }    
    }
    if(ms.empty()){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back(*ms.rbegin());
    answer.push_back(*ms.begin());
    
    return answer;
}