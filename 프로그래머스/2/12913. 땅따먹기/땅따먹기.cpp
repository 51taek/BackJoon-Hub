#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dp[100005][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    int n = land.size();
    
    for(int i=0;i<4;i++){
        dp[0][i] = land[0][i];
    }
    
    for(int i=1;i<land.size();i++){
        dp[i][0] = max({dp[i-1][1], dp[i-1][2], dp[i-1][3]}) + land[i][0];
        dp[i][1] = max({dp[i-1][0], dp[i-1][2], dp[i-1][3]}) + land[i][1];
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][3]}) + land[i][2];
        dp[i][3] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + land[i][3];
    }
    
    answer = max({dp[n-1][0], dp[n-1][1], dp[n-1][2], dp[n-1][3]});

    return answer;
}