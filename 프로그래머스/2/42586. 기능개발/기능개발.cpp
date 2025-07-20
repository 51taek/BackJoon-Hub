#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p, vector<int> speeds) {
    vector<int> answer;
    vector<int> v;
    for(int i=0;i<p.size();i++){
        int d = (100 - p[i] + speeds[i] -1) / speeds[i];
        v.push_back(d);
    }
    
    int deploy_day = v[0];
    int count = 1;
    
    for(int i = 1; i < v.size(); i++) {
        if(v[i] <= deploy_day) {
            count++;
        } else {
            answer.push_back(count);
            deploy_day = v[i];
            count = 1;
        }
    }
    answer.push_back(count);
    return answer;
}