#include <string>
#include <vector>

using namespace std;

int a[100002];
int b[100002];

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    a[1] = 1;
    b[1] = tops[0] == 1 ? 3 : 2;
    
    for(int i=2;i<100002;i++){
        if(tops[i-1] == 1){
            a[i] = (a[i-1] + b[i-1]) % 10007;
            b[i] = (2 * a[i-1] + 3 * b[i-1]) % 10007;
        } else {
            a[i] = (a[i-1] + b[i-1]) % 10007;
            b[i] = (a[i-1] + 2 * b[i-1]) % 10007;
        }
        if(i==n) break;
    }
    answer = (a[n] + b[n]) % 10007;
    return answer;
}