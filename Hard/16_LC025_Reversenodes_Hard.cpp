 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);

        dummy->next = head;

        ListNode* previous = dummy;

        while(true) {

            ListNode* kth = previous;

            for(int i = 0; i < k; i++) {

                kth = kth->next;

                if(kth == nullptr) {

                    return dummy->next;

                }
            }

            ListNode* nextGroup = kth->next;

            ListNode* prev = nextGroup;

            ListNode* current = previous->next;

            while(current != nextGroup) {

                ListNode* temp = current->next;

                current->next = prev;

                prev = current;

                current = temp;
            }

            ListNode* temp = previous->next;

            previous->next = kth;

            previous = temp;
        }

        return dummy->next;
    }
};
