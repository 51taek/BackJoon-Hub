#include <string>
#include <vector>

using namespace std;

long long dp[105][105];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0;i<puddles.size();i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        
        dp[y-1][x-1] = -1;
    }
    
    dp[0][0] = 1;
    
    
    for(int j = 1; j < m; j++){
        if(dp[0][j] == -1) break;
        dp[0][j] = dp[0][j-1];
    }

    for(int i = 1; i < n; i++){
        if(dp[i][0] == -1) break;
        dp[i][0] = dp[i-1][0];
    }
    
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp[i][j] == -1) continue;
            
            if(dp[i-1][j] == -1) dp[i][j] = dp[i][j-1];
            else if(dp[i][j-1] == -1) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            
            dp[i][j] %= 1000000007;
        }
    }
    
    answer = dp[n-1][m-1];
    
    
    return answer;
}