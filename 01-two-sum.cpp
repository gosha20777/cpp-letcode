//
// Created by gosha20777 on 7/20/22.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++)
            for (int j = 0; j < i; j++)
                if (numbers[i] + numbers[j] == target){
                    result.push_back(j);
                    result.push_back(i);
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
