#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int,int> m;
    
    for(int i=0;i<nums.size();i++){
        if(m.find(nums[i]) == m.end()){
            m.insert({nums[i],1});
        }else{
            m[nums[i]]++;
        }
    }
    
    answer = m.size();
    
    if(m.size() > nums.size() / 2) answer = nums.size() / 2;
    
    
    return answer;
}