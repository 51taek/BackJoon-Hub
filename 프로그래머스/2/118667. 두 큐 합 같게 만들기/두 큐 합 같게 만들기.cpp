#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum = 0;
    long long q1Sum = 0;
    
    queue<int> q1;
    queue<int> q2;
    
    for(int i : queue1){
        sum += i;
        q1Sum += i;
        q1.push(i);
    }

    for(int i : queue2){
        sum += i;
        q2.push(i);
    }

    sum /= 2;
    
    int limit = (queue1.size() + queue2.size()) * 3;
    
    while(answer <= limit){
        if(q1Sum == sum) return answer;
        
        if(q1Sum < sum){
            if(q2.empty()) return -1;
            
            int cur = q2.front();
            q2.pop();
            q1.push(cur);
            
            q1Sum += cur;
        }
        else{
            if(q1.empty()) return -1;
            
            int cur = q1.front();
            q1.pop();
            q2.push(cur);
            
            q1Sum -= cur;
        }
        
        answer++;
    }
    
    return -1;
}