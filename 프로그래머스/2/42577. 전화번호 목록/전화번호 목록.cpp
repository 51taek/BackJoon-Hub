#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone) {
    bool answer = true;
    
    sort(phone.begin(), phone.end());
    
    for(int i=0;i<phone.size()-1;i++){
        if(phone[i+1].find(phone[i]) == 0){
            return false;
            break;
        }
    }
    
    return true;
}