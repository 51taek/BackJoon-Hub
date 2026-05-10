#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isClosed(string t){
    
    stack<char> s;
    
    for(int i=0;i<t.size();i++){
        if(t[i] == '(' || t[i] == '{' || t[i] == '['){
            s.push(t[i]);
        } else{
            if(s.empty()) return false;
            if(!isMatch(s.top(), t[i])) return false;
            s.pop();
        }
    }
    return s.empty();
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++){
        char temp = s[0];
        s.erase(0,1);
        s += temp;
        if(isClosed(s)) answer++;
    }
    
    return answer;
}