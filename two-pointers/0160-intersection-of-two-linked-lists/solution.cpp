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
    ListNode *collision(ListNode *headA, ListNode *headB,int n){
        ListNode *t1=headA;
        while(n){
            t1=t1->next;
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
        int cnt1=0;
        while(temp){
            cnt1++;
            temp=temp->next;
            
        }
        int cnt2=0;
        while(temp2)2{
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
