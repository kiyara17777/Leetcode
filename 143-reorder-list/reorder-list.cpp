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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=slow->next;
        slow->next=NULL;

        ListNode* prev=NULL;
        ListNode* curr=newhead;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        newhead=prev;
        ListNode* temp=head;
        while(temp!=NULL && newhead!=NULL){
            ListNode* tempnext=temp->next;
            ListNode*  newheadnext=newhead->next;

            temp->next=newhead;
            newhead->next=tempnext;

            temp=tempnext;
            newhead=newheadnext;
        }
        
    }
};