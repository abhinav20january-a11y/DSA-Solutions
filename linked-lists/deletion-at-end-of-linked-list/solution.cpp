/* Linked List Node Structure
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        Node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        Node *tail=temp->next;
        temp->next=nullptr;
        delete(tail);
        return head;
        
    }
};
