#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> v, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i=0;i<v.size();++i){
        q.push({v[i], i});
        pq.push(v[i]);
    }
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(t.first == pq.top()){
            pq.pop();
            answer++;
            if(location == t.second){
                return answer;
            }
        } else{
            q.push(t);
        }
        
    }
    
    return answer;
}