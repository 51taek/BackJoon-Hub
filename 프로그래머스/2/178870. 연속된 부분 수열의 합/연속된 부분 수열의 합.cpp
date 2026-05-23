#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size();
    queue<int> q;
    
    int st;
    int en = 0;
    int sum = 0;
    int minLen = 10e8;
    
    for(st=0;st<n;st++){
        while(en < n && sum < k){
            sum += sequence[en];
            en++;
        
        }
        
        if(sum == k){
            int len = en - st;
            
            if(len < minLen){
                minLen = len;
                answer = {st, en - 1};
            }
        }
        
        sum -= sequence[st];
    }
    
    return answer;
}