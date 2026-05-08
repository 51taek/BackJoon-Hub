#include <string>
#include <vector>

using namespace std;
int dp[10005];

int solution(int n) {
    int answer = 0;
    
    for(int j=1;j<n;j++){
        int sum = 0;
        for(int i=j;i<n;i++){
            sum += i;
            if(sum > n){
                break;
            } else if(sum == n){
                answer++;
                break;
            }
        }
    }
    
    
    
    return answer+1;
}