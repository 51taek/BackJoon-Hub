#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    set<int> left;
    map<int,int> right;
    
    for(int i=0;i<topping.size();i++){
        right[topping[i]]++;
    }
    
    for(int i=0;i<topping.size();i++){
        left.insert(topping[i]);
        
        if(right[topping[i]] == 1){
            right.erase(topping[i]);
        } else {
            right[topping[i]]--;
        }
        
        if(left.size() == right.size()){
            answer++;
        }
        
    }
        
    return answer;
}