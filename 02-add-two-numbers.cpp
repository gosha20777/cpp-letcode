//
// Created by gosha20777 on 7/21/22.
//
#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* current_ptr = result;
        int overflow = 0;

        while (l1 != nullptr || l2 != nullptr){
            int l1_val = (l1 == nullptr) ? 0 : l1->val;
            int l2_val = (l2 == nullptr) ? 0 : l2->val;
            int sum = l1_val + l2_val + overflow;
            overflow = sum / 10;
            current_ptr->next = new ListNode(sum % 10);
            current_ptr = current_ptr->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (overflow > 0)
            current_ptr->next = new ListNode(overflow);
        return result->next;
    }
};

int main(){
    ListNode* input1 = new ListNode(2);
    ListNode* input1_1 = new ListNode(4);
    ListNode* input1_2 = new ListNode(3);
    input1->next = input1_1;
    input1_1->next = input1_2;

    ListNode* input2 = new ListNode(2);
    ListNode* input2_1 = new ListNode(4);
    input2->next = input2_1;


    Solution s;
    auto result = s.addTwoNumbers(input1, input2);
    while (result->next != nullptr){
        cout << "->" << result->val;
        result = result->next;
    }
    cout << "->" << result->val << endl;
    return 0;
}
