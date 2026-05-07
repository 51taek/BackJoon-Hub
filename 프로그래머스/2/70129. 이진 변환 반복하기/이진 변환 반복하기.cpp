#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int first = 0;
    int second = 0;
    
    while(s != "1"){
        int er = 0;
        //1. x의 모든 0 제거
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '0'){
                s.erase(i,1);
                er++;
            }
        }
        second += er;
        //2. x의 길이 2진법으로
        int len = s.size();
        string result = "";
        while(len >0){
            result = to_string(len % 2) + result;
            len /= 2;
        }
        s = result;
        first++;
    }
    
    answer.push_back(first);
    answer.push_back(second);
    
    
    return answer;
}