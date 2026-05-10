#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string,int> m;
    
    for(int i=0; i<want.size();i++){
        m[want[i]] += number[i];
    }
    
    map<string,int> temp;
    
    for(int i=0;i<=discount.size()-10;i++){
        temp = m;
        for(int j=i;j<i+10;j++){
            auto it = temp.find(discount[j]);
            if (it != temp.end()) {
                it->second--;
                
                if (it->second == 0) {
                    temp.erase(it);
                }
            }
        }
        if(temp.size() == 0) answer++;
    }
    
    return answer;
}