#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<string> st;
    
    for(string stree: skill_trees){
        string temp="";
        
        for(char c: stree){
            if(skill.find(c) != string::npos) temp += c;
        }
        
        if(skill.substr(0, temp.size()) == temp){
            answer++;
        }
    }
    
    return answer;
}