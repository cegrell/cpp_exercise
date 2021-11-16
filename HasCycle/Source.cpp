#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}    
};

class Solution {
public:
    bool hasCycle(ListNode* head) {

        ListNode* s = head, * f = head; //take slow and fast pointers

        //move slow by 1 step and fast 2 step
        //if there will be cycle and slow and fast will definetly meet at some point (s==f)
        //else fast will reach to end

        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f)
                return true;
        }
        return false;
    }
};

void main() {
    Solution s;
    ListNode first(5);
    ListNode second(3);
    ListNode third(4);

    first.next = &second;
    second.next = &third;
    third.next = &first;

    bool flag = s.hasCycle(&first);
    std::cout << flag << std::endl;
}