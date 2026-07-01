#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    
    char a[3] = {'1','2','4'};
    
    while(n>0){
        n--;
        answer += a[n%3];
        n /= 3;
    }
    
    reverse(answer.begin(), answer.end());
    
    
    return answer;
}