// AddTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}        
    };
    
    void Insert(struct ListNode* head, int newData) {
        struct ListNode* newNode = new ListNode(newData);
        if (head == nullptr)
            *head = newNode;
        else {

        }

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l3;

        while (l1 != nullptr || l2 != nullptr || carry > 0)
        {
            ListNode* next;
            l3->next = next;
            int new_val = 0;
            if (l1 != nullptr && l2 != nullptr)int new_val = l1->val + l2->val;
            else if (l1 != nullptr) int new_val = l2->val;
            else if (l2 != nullptr) int new_val = l1->val;
            new_val += carry;

            if (new_val > 10) carry = 1;
            l3->val = new_val % 10;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return l3;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
