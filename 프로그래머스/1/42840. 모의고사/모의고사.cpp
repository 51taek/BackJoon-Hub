#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int n = answers.size();
    int a[10002] = {1,2,3,4,5};
    int b[10002] = {2,1,2,3,2,4,2,5};
    int c[10002] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=5;i<n;i++){
        a[i] = a[i-5];
    }
    for(int i=8;i<n;i++){
         b[i] = b[i-8];
    }
    for(int i=10;i<n;i++){
         c[i] = c[i-10];
    }
    
    int aa = 0;
    int ba = 0;
    int ca = 0;
    
    for(int i=0;i<n;i++){
        if(answers[i] == a[i]){
            aa++;
        }
        if(answers[i] == b[i]){
            ba++;
        }
        if(answers[i] == c[i]){
            ca++;
        }
    }
    
    int ma = max(aa,ba);
    ma = max(ma,ca);
    if(ma == aa) answer.push_back(1);
    if(ma == ba) answer.push_back(2);
    if(ma == ca) answer.push_back(3);
    
    return answer;
}