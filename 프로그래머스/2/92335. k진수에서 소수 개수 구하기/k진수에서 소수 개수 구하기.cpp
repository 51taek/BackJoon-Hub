#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long num) {
    if (num < 2) return false;

    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s="";
    while(n>0){
        int m = n % k;
        s = to_string(m) + s;
        n /= k;
    }
    
    vector<long long> v;
    
    string sp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (!sp.empty()) {
                v.push_back(stoll(sp));
                sp = "";
            }
        }
        else {
            sp += s[i];
        }
    }

    if (!sp.empty()) {
        v.push_back(stoll(sp));
    }
    
    for(int i=0;i<v.size();i++){
        if(isPrime(v[i])) answer++;
    }
    
    
    return answer;
}