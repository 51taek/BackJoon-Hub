#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2;i<n;i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> result;
    sort(numbers.begin(), numbers.end());

    do {
        for (int len = 1; len <= numbers.size(); len++) {
            string part = numbers.substr(0, len);  
            int num = stoi(part);
            if (isPrime(num)) {
                result.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return result.size();
}