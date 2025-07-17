#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end()); // 요청 시간 기준 정렬

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int time = 0, idx = 0, total = 0, count = jobs.size();

    while (idx < jobs.size() || !pq.empty()) {
        // 현재 시간 이하로 들어온 작업들 pq에 추가
        while (idx < jobs.size() && jobs[idx][0] <= time) {
            pq.push({jobs[idx][1], jobs[idx][0]}); // {소요시간, 요청시간}
            idx++;
        }

        if (!pq.empty()) {
            auto [duration, start] = pq.top();
            pq.pop();
            time += duration;
            total += (time - start); // 작업 완료 시점 - 요청 시점
        } else {
            time = jobs[idx][0]; // 다음 작업이 들어올 때까지 대기
        }
    }

    return total / count;
}