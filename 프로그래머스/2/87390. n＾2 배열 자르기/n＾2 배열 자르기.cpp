#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i<=right;i++){
        int r = i / n;
        int c = i % n;
        int m = max(r,c);
        answer.push_back(m+1);
    }
    
    return answer;
}