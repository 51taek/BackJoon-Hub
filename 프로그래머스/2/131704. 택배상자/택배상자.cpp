#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    int n = order.size();
    stack<int> temp;
    
    for (int box = 1; box <= n; box++) {
        temp.push(box);

        while (!temp.empty() && temp.top() == order[answer]) {
            temp.pop();
            answer++;

            if (answer == n) break;
        }
    }
    
    return answer;
}