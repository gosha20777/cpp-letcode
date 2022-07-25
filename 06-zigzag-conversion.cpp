//
// Created by gosha20777 on 7/25/22.
//

//
// Created by gosha20777 on 7/25/22.
//


#include "iostream"
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        string result = "";
        vector<string> rows(numRows);
        bool is_down = true;
        int row_idx = 0;

        for (const char& c : s){
            rows[row_idx].push_back(c);
            if (row_idx == numRows - 1)
                is_down = false;
            else if (row_idx == 0)
                is_down = true;
            row_idx = is_down ? row_idx + 1 : row_idx - 1;
        }

        for (const string& item : rows)
            result += item;
        return result;
    }
};


int main(){
    string str = "PAYPALISHIRING";

    Solution s;
    auto result = s.convert(str, 3);
    cout << result << endl;
    return 0;
}
