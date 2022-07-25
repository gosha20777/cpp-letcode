//
// Created by gosha20777 on 7/21/22.
//

#include "iostream"
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        set<char> str_set;
        for (char c : s){
            int old_size;
            old_size = str_set.size();
            str_set.insert(c);
            if (str_set.size() > result)
                result = str_set.size();
            if (str_set.size() == old_size){
                str_set.clear();
                str_set.insert(c);
            }
        }
        return result;
    }
};

int main(){
    string str = "aab";
    Solution s;
    auto result = s.lengthOfLongestSubstring(str);
    cout << result << endl;
    return 0;
}
