
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        while( head!=NULL &&  head->val==val){
            ListNode *temp=head;
            head=head->next;
            delete(temp);
        }
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp){
            if(temp->val==val){
                prev->next=temp->next;
                ListNode *del=temp;
                temp=temp->next;
                delete(del);

            }
            else{
            prev=temp;
            temp=temp->next;

            
        }
        
        
    }
    return head;}
};
