#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int,int> m;
    
    sort(weights.begin(), weights.end());
    
    for(int w: weights){
        
        answer += m[w];
        
        if(w * 2 % 3 == 0){
            answer += m[w * 2 / 3];
        }
        if(w % 2 == 0){
            answer += m[w / 2];
        }
        if(w * 3 % 4 == 0){
            answer += m[w * 3 / 4];
        }
        m[w]++;
    }
    
    return answer;
}