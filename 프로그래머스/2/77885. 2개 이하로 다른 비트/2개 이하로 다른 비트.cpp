#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long num : numbers){
        if(num % 2 == 0){
            answer.push_back(num + 1);
        } else {
            long long bit = 1;
            
            while(num & bit){
                bit <<= 1;
            }
            
            answer.push_back(num + bit - (bit >> 1));
        }
    }
    
    return answer;
    
    
    return answer;
}