#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int maxNode = 0;
    for (auto &e : edges) maxNode = max({maxNode, e[0], e[1]});

    vector<int> in(maxNode + 1, 0), out(maxNode + 1, 0);
    vector<char> seen(maxNode + 1, 0);

    for (auto &e : edges) {
        int u = e[0], v = e[1];
        out[u]++; in[v]++;
        seen[u] = 1; seen[v] = 1;       // ✅ 실제로 존재하는 노드 표시
    }

    int start = -1, donut = 0, bar = 0, eight = 0;

    // ✅ 생성점: in==0 && out>=2 이면서 실제 등장한 노드만
    for (int i = 1; i <= maxNode; i++) {
        if (!seen[i]) continue;
        if (in[i] == 0 && out[i] >= 2) {
            start = i;
            break;                      // 하나만 존재
        }
    }

    // ✅ 막대/8자 세기: 존재 노드만
    for (int i = 1; i <= maxNode; i++) {
        if (!seen[i] || i == start) continue;
        if (out[i] == 0) bar++;
        else if (out[i] == 2) eight++; // 8자 중앙은 정확히 out=2
    }

    // ✅ 도넛 개수 = 생성점에서 뻗은 전체 - 막대 - 8자
    donut = out[start] - bar - eight;

    return {start, donut, bar, eight};
}
