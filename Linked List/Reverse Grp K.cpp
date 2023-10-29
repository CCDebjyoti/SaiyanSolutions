class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ||k==0)return head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*curr=dummy,*pre=dummy,*nex=dummy;
        int count =0;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        while(count>=k){
            curr=pre->next;
            nex=curr->next;
            for(int i=0;i<k-1;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            count=count-k;
        }
        return dummy->next;
    }
};
