#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    int l = n;
    while(l>1){
        answer++;
        l /= 2;
    }
        
    int pos = 1;

    while(n>1){
        cout << "pos: " << pos << endl;
        int half = (pos + n) / 2;
        cout << "half: " << half << endl;
        if((a <= half && b > half) || (a > half & b <= half)){
            return answer;
        }
        if(a > half) pos = half;
        else n = half;
        answer--;
    }

    return answer;
}