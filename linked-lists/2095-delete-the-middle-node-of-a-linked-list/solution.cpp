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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;

        }
        ListNode *temp2=head;
        int middle=(cnt)/2;
        while(temp2){
            middle--;
            if(middle==0){
                break;
            }
            temp2=temp2->next;
        }
        ListNode *delnode=temp2->next;
        temp2->next=temp2->next->next;
        delete(delnode);
        return head;
        


        
    }
};
