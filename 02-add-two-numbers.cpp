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
        int num1 = 0, num2 = 0, i1 = 1, i2 = 1;
        while (l1->next != nullptr){
            num1 = num1 + i1 * l1->val;
            i1 = i1 * 10;
            l1 = l1->next;
        }
        num1 = num1 + i1 * l1->val;

        while (l2->next != nullptr){
            num2 = num2 + i2 * l2->val;
            i2 = i2 * 10;
            l2 = l2->next;
        }
        num2 = num2 + i2 * l2->val;

        int sum_mum = num1 + num2;
        ListNode* listNode = new ListNode(sum_mum % 10);
        ListNode* result = listNode;

        sum_mum = sum_mum / 10;
        while (sum_mum != 0){
            listNode->next = new ListNode(sum_mum % 10);
            sum_mum = sum_mum / 10;
            listNode = listNode->next;
        }
        return result;
    }
};

int main(){
    ListNode* input1 = new ListNode(2);
    ListNode* input1_1 = new ListNode(4);
    ListNode* input1_2 = new ListNode(3);
    input1->next = input1_1;
    input1_1->next = input1_2;


    Solution s;
    auto result = s.addTwoNumbers(input1, input1);
    while (result->next != nullptr){
        cout << "->" << result->val;
        result = result->next;
    }
    cout << "->" << result->val << endl;
    return 0;
}
