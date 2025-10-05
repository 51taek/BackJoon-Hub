#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (char ch : name) {
        answer += min(ch - 'A', 'Z' - ch + 1);
    }
    
    int n = name.size();
    int move = n - 1;
    for (int i = 0; i < n; i++) {
        int next = i + 1;

        while (next < n && name[next] == 'A') next++;

        move = min(move, i + n - next + min(i, n - next));
    }
    return answer + move;
}