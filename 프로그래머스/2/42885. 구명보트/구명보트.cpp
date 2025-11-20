#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int n = people.size();
    int en = n-1;
    int st = 0;
    
    while(st <= en){
        if(people[st] + people[en] <= limit){
            st++;
        }
        
        en--;
        answer++;
    }
    
    return answer;
}