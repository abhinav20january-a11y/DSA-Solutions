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
    ListNode *collison(ListNode *headA, ListNode *headB,int n){
        ListNode *t1=headB;
        while(n){
            t1=t1->next;
            n--;
        }
        ListNode *t2=headA;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
        }
        return t2;



    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA;
        ListNode *temp2=headB;
        int cnt1=0;
        while(temp){
            cnt1++;
            temp=temp->next;
            
        }
        int cnt2=0;
        while(temp2){
            cnt2++;
            temp2=temp2->next;
            
        }
        if(cnt2>cnt1){
            return collison(headA,headB,cnt2-cnt1);
        }
        else{
            return collison(headB,headA,cnt1-cnt2);
        }

        
    }
};
