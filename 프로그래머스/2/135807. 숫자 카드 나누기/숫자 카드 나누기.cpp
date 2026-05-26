#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& arr, int gc) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] % gc == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];
    
    for(int i = 1; i < arrayA.size(); i++) {
        gcdA = gcd(gcdA, arrayA[i]);
    }
    
    for(int i = 1; i < arrayB.size(); i++) {
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    if(check(arrayB, gcdA)) {
        answer = max(answer, gcdA);
    }
    
    if(check(arrayA, gcdB)) {
        answer = max(answer, gcdB);
    }
    
    return answer;
}