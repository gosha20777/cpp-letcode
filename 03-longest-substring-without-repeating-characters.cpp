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
        int begin_ptr = 0;
        int end_ptr = 0;
        set<char> str_set;

        while(end_ptr < s.size()){
            if(str_set.count(s[end_ptr]) == 0){
                str_set.insert(s[end_ptr]);
                result = max(int(str_set.size()), result);
                end_ptr++;
            } else{
                str_set.erase(s[begin_ptr]);
                begin_ptr++;
            }
        }
        return result;
    }
};

int main(){
    string str = "aabccabc";

    Solution s;
    auto result = s.lengthOfLongestSubstring(str);
    cout << result << endl;
    return 0;
}
