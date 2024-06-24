class Solution {
public:
 ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
      }
        ListNode*slow=head , *fast=head ;
        while(fast->next !=NULL && fast->next->next !=NULL ){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverseList(slow->next);
        slow=slow->next;
       while(slow!=NULL){
           if(slow->val!=head->val)
           return false;

           slow=slow->next;
        head=head->next;
       }
       return true;
    }
};
