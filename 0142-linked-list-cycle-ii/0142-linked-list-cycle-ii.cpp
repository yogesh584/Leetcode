/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        bool isCyclePresent = false;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCyclePresent = true;
                break;
            }
        }

        if(isCyclePresent){
            slow = head;
            while(slow != fast){
                if(slow->next != NULL)  slow = slow->next;
                if(fast->next != NULL)  fast = fast->next;
            }

            return slow;
        }
        else{
            return NULL;
        }
    }
};

// [3,2,0,-4]
// 1
// [1,2]
// 0
// [1]
// -1
// []
// -1
// [1,2]
// -1