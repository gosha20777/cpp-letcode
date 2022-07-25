//
// Created by gosha20777 on 7/25/22.
//


#include "iostream"
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        string result = "";
        for (int i = 0; i < s.size(); i++){
            auto res1 = getPalindrome(s, i, i);
            auto res2 = getPalindrome(s, i, i+1);

            if (res1.size() > result.size())
                result = res1;
            if (res2.size() > result.size())
                result = res2;
        }
        return result;
    }
private:
    string getPalindrome(const string& s, int left, int right){
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
};


int main(){
    string str = "bb";

    Solution s;
    auto result = s.longestPalindrome(str);
    cout << result << endl;
    return 0;
}
