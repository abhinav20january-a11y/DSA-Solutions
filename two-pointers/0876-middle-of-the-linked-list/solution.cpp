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
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        int middle=(cnt)/2+1;
        ListNode *temp2=head;
        
        while(temp2){
            
            middle--;
            if(middle==0){
                break;
            }
            temp2=temp2->next;

        }





 return temp2;
            
        }
       
        


        
        
    };
