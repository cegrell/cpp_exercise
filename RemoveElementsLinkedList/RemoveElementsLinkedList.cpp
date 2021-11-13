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

    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

        // Find first node with != val
        while (head->val == val)
        {
            if (head->val == val) head = head->next;
            if (head == nullptr) return nullptr;
        }

        // Now first val is OK, sort the rest        
        ListNode* node = head;
        while (node != nullptr)
        {
            if (node->next != nullptr && node->next->val == val)
            {
                ListNode* tmp_node = node->next->next;
                // Many vals in row, move forward till != val
                while (tmp_node != nullptr && tmp_node->val == val)
                {
                    if (tmp_node->val == val) tmp_node = tmp_node->next;
                }
                node->next = tmp_node;
                node = tmp_node;
            }
            else
            {
                node = node->next;
            }
        }
        return head;
    }
};


int main()
{
    Solution s;
    s.removeElements();
    std::cout << "Hello World!\n";
}
