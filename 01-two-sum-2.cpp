//
// Created by gosha20777 on 7/20/22.
//
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i=0; i<nums.size(); i++) {
            if ( m.find(target - nums[i]) == m.end() ) {
                m[nums[i]] = i;
            }else{
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(){
    vector<int> numbers{ 3,3 };
    Solution s;
    auto result = s.twoSum(numbers, 6);
    for (int i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}
