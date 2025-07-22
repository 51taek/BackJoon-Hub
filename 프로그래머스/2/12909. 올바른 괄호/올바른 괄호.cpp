#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int a = 0;
    
    if(s.size() == 0) return false;
    
    if(s[0] == ')' || s[s.size()-1] == '(') return false;

    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            a++;
        }else{
            a--;
            if(a<0) return false;
        }
    }
    
    if(a == 0){
        return true;
    } else {
        return false;
    }
}