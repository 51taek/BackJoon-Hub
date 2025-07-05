#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    bool found = false;
    
    for(int i=1;i<10000;i++){
        if(found) break;
        for(int j=1;j<10000;j++){
            if((i*j == brown + yellow) && ((i-2) * (j-2) == yellow)){
                answer.push_back(j);
                answer.push_back(i);
                found=true;
                break;
            }
        }
    }
    return answer;
}