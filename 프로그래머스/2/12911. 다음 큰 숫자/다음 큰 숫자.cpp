#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


int oneNum(int on){
    int cnt = 0;

    while (on > 0) {
        if (on % 2 == 1) cnt++;
        on /= 2;
    }

    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int a = __builtin_popcount(n);
    while(1){
        n++;
        if(a == __builtin_popcount(n)) return n;
    }
}