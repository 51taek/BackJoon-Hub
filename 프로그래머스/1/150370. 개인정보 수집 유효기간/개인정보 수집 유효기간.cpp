#include <string>
#include <vector>
#include <map>

using namespace std;

int toDays(const string& date) {
    int y, m, d;
    sscanf(date.c_str(), "%d.%d.%d", &y, &m, &d);
    return y * 12 * 28 + m * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> m;
    int td = toDays(today);
    
    for(int i=0;i<terms.size();i++){
        string type = terms[i].substr(0,1);
        string d = terms[i].substr(2);
        int duration = stoi(d);
        m[type] = duration;
    }
    
    for(int i=0;i<privacies.size();i++){
        string d = privacies[i].substr(0,10);
        string t = privacies[i].substr(11);
        
        int date = toDays(d);
        int plus = m[t] * 28;
        date += plus;
        if(date <= td){
            answer.push_back(i+1);
        }
        
    }
    
    return answer;
}