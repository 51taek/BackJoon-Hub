#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            isFirst = true;
        }else{
            if(isFirst){
                s[i] = toupper(s[i]);
                isFirst = false;
            }else{
                s[i] = tolower(s[i]);
            }
        }
    }
    
    return s;
}