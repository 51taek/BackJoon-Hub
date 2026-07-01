#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    long long soldiers = n;

    for (int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);

        if (pq.size() > k) {
            soldiers -= pq.top();
            pq.pop();
        }

        if (soldiers < 0) {
            return i;
        }
    }

    return enemy.size();
}