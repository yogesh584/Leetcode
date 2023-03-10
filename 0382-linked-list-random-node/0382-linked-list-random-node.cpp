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
    ListNode* head = NULL;

    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* tempHead = head;
        int nodeSeenYet = 0;
        ListNode* randomNode = nullptr;
        while(tempHead != NULL){
            nodeSeenYet++;

            int random = rand() % nodeSeenYet;
            if(random == nodeSeenYet-1){
                randomNode = tempHead;
            }
            tempHead = tempHead->next;
        }

        return randomNode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */