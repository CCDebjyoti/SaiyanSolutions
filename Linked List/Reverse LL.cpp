class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode*temp=NULL,*nxt=head;
        while(head!=NULL){
            nxt=head->next;
            head->next=temp;
            temp=head;
            head=nxt;
        }
        return temp;
    }
};
