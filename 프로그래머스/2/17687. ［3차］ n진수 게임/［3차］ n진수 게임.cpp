#include <string>
#include <vector>

using namespace std;

string convert(int num, int n) {
    string chars = "0123456789ABCDEF";

    if (num == 0) return "0";

    string result = "";

    while (num > 0) {
        result = chars[num % n] + result;
        num /= n;
    }

    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string total = "";
    int num = 0;

    while (total.size() < t * m) {
        total += convert(num, n);
        num++;
    }

    for (int i = p - 1; answer.size() < t; i += m) {
        answer += total[i];
    }

    return answer;
}