#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    vector<char> v;
    for(char c: number){
        while(!v.empty() && k > 0 && v.back() < c){
            v.pop_back();
            k--;
        }
        v.push_back(c);
    }
    
    while(k--){
        v.pop_back();
    }
    
    for(char c: v){
        answer += c;
    }
    
    return answer;
}