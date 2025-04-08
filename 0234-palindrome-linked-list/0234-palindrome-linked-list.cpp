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

private:

    ListNode* reverse(ListNode* node){

        if(node == NULL || node -> next == NULL){
            return node;
        }

        ListNode* newHead = reverse(node->next);
        ListNode* front = node -> next;
        front -> next = node;
        node -> next = NULL;

        return newHead;

    } 

public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){

            slow = slow->next;
            fast = fast->next->next;

            
        }

        ListNode* newHead = reverse(slow -> next);
        fast = newHead;
        slow = head;
        while(fast != NULL){
            if(slow->val != fast->val){
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* mid2 = reverse(newHead);
        return true;
    }
};