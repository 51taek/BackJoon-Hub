#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> tw) {
    int answer = 0;
    int wnow = 0;
    queue<pair<int,int>> q;
    vector<pair<int, int>> bridge;
    
    for(int i=0; i<tw.size(); i++){
        q.push({tw[i], bridge_length});
    }
    
    while(!q.empty() || !bridge.empty()){        
        // 1. 다리 위 트럭들 시간 감소 및 제거
        for (auto it = bridge.begin(); it != bridge.end(); ) {
            it->second--;
            if (it->second == 0) {
                wnow -= it->first;
                it = bridge.erase(it);
            } else {
                ++it;
            }
        }

        // 2. 다음 트럭 올릴 수 있는지 확인
        if (!q.empty() && wnow + q.front().first <= weight) {
            auto t = q.front(); q.pop();
            bridge.push_back(t);
            wnow += t.first;
        }

        answer++;
    }
    return answer;
}
