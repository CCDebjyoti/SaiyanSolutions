class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
    if(head==NULL || head->next==NULL){
    return false;
    }
     while(fast->next !=NULL && fast->next->next !=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            return true;
        }
        return false;

    }
};
