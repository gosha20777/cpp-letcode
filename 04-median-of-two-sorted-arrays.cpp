//
// Created by gosha20777 on 7/21/22.
//

#include "iostream"
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        if (len & 1){
            return findKth(nums1, nums2,len / 2 + 1);
        } else{
            return (findKth(nums1,nums2,len / 2) + findKth(nums1,nums2,len / 2 + 1))/2;
        }
    }

private:
    double findKth(vector<int> nums1, vector<int> nums2, int k){
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2)
            return findKth(nums2,nums1, k);
        if (len1 == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0],nums2[0]);

        int a = min(k / 2, len1), b = k - a;
        if (nums1[a - 1] < nums2[b - 1])
            return findKth(vector<int>(nums1.begin() + a,nums1.end()),nums2,k - a);
        else if (nums1[a - 1] > nums2[b - 1])
            return findKth(nums1,vector<int>(nums2.begin() + b,nums2.end()),k - b);
        else
            return nums1[a - 1];
    }
};

int main(){
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution s;
    auto result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}
